/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:50:17 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/17 18:35:20 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define U_DIV 1
#define V_DIV 1
#define V_MOVE 0.0

static void			set_sprite(t_info *info, int *sprite_order,\
double *sprite_distance)
{
	int				i;

	i = 0;
	while (i < info->num_sprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((info->pos_x - g_sprite[i].x) \
		* (info->pos_x - g_sprite[i].x) \
		+ (info->pos_y - g_sprite[i].y) * (info->pos_y - g_sprite[i].y));
		i++;
	}
}

static void			spr_ray_init_1(t_sprite_ray *spr_ray,\
		t_info *info, int order_num)
{
	spr_ray->sprite_x = g_sprite[order_num].x - info->pos_x;
	spr_ray->sprite_y = g_sprite[order_num].y - info->pos_y;
	spr_ray->inv_det = 1.0 / (info->plane_x * info->dir_y \
			- info->dir_x * info->plane_y);
	spr_ray->transform_x = spr_ray->inv_det \
	* (info->dir_y * spr_ray->sprite_x \
	- info->dir_x * spr_ray->sprite_y);
	spr_ray->transform_y = spr_ray->inv_det \
	* (-info->plane_y * spr_ray->sprite_x \
	+ info->plane_x * spr_ray->sprite_y);
	spr_ray->sprite_screen_x = (int)((g_width / 2) \
			* (1 + spr_ray->transform_x / spr_ray->transform_y));
	spr_ray->v_move_screen = (int)(V_MOVE / spr_ray->transform_y);
	spr_ray->sprite_height = (int)fabs((g_height / spr_ray->transform_y) \
			/ V_DIV);
}

static void			spr_ray_init_2(t_sprite_ray *spr_ray, t_info *info)
{
	spr_ray->draw_start_y = -spr_ray->sprite_height / 2 \
							+ g_height / 2 + spr_ray->v_move_screen;
	if (spr_ray->draw_start_y < 0)
		spr_ray->draw_start_y = 0;
	spr_ray->draw_end_y = spr_ray->sprite_height / 2 \
	+ g_height / 2 + spr_ray->v_move_screen;
	if (spr_ray->draw_end_y >= g_height)
		spr_ray->draw_end_y = g_height - 1;
	spr_ray->sprite_width = (int)fabs((g_height / spr_ray->transform_y) \
							/ U_DIV);
	spr_ray->draw_start_x = -spr_ray->sprite_width / 2 \
							+ spr_ray->sprite_screen_x;
	if (spr_ray->draw_start_x < 0)
		spr_ray->draw_start_x = 0;
	spr_ray->draw_end_x = spr_ray->sprite_width / 2 \
	+ spr_ray->sprite_screen_x;
	if (spr_ray->draw_end_x >= g_width)
		spr_ray->draw_end_x = g_width - 1;
}

static void			set_spr_tex(t_sprite_ray *spr_ray, \
		t_info *info, int order_num, int stripe)
{
	int				tex_x;
	int				tex_y;
	int				y;
	int				d;
	int				color;

	tex_x = (int)((256 * (stripe - (-spr_ray->sprite_width / 2 \
						+ spr_ray->sprite_screen_x)) \
				* TEX_WIDTH / spr_ray->sprite_width) / 256);
	if (spr_ray->transform_y > 0 && stripe > 0 && stripe < g_width \
		&& spr_ray->transform_y < info->z_buffer[stripe])
	{
		y = spr_ray->draw_start_y;
		while (y < spr_ray->draw_end_y)
		{
			d = (y - spr_ray->v_move_screen) * 256 - g_height \
				* 128 + spr_ray->sprite_height * 128;
			tex_y = ((d * TEX_HEIGHT) / spr_ray->sprite_height) / 256;
			color = info->texture[g_sprite[order_num].texture]\
					[TEX_WIDTH * tex_y + tex_x];
			if ((color & 0x00FFFFFF) != 0)
				info->buf[y][stripe] = color;
			y++;
		}
	}
}

void				sprite_casting(t_info *info)
{
	int				sprite_order[info->num_sprites];
	double			sprite_distance[info->num_sprites];
	t_sprite_ray	spr_ray;
	int				i;
	int				num;

	i = 0;
	set_sprite(info, sprite_order, sprite_distance);
	sort_sprites(sprite_order, sprite_distance, info->num_sprites);
	i = 0;
	while (i < info->num_sprites)
	{
		spr_ray_init_1(&spr_ray, info, sprite_order[i]);
		spr_ray_init_2(&spr_ray, info);
		num = spr_ray.draw_start_x;
		while (num < spr_ray.draw_end_x)
		{
			set_spr_tex(&spr_ray, info, sprite_order[i], num);
			num++;
		}
		i++;
	}
}
