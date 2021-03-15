/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:16:21 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 16:16:22 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			w_ray_init(t_wall_ray *w_ray, t_info *info, int x)
{
	w_ray->camera_x = 2 * x / (double)g_width - 1;
	w_ray->raydir_x = info->dir_x + info->plane_x * w_ray->camera_x;
	w_ray->raydir_y = info->dir_y + info->plane_y * w_ray->camera_x;
	w_ray->delta_dist_x = fabs(1 / w_ray->raydir_x);
	w_ray->delta_dist_y = fabs(1 / w_ray->raydir_y);
	w_ray->hit = 0;
	w_ray->map_x = (int)info->pos_x;
	w_ray->map_y = (int)info->pos_y;
}

static void			set_draw_num(t_wall_ray *w_ray, t_info *info)
{
	if (w_ray->side == 0)
		w_ray->perp_wall_dist = (w_ray->map_x - info->pos_x \
		+ (1 - w_ray->step_x) / 2) / w_ray->raydir_x;
	else
		w_ray->perp_wall_dist = (w_ray->map_y - info->pos_y \
		+ (1 - w_ray->step_y) / 2) / w_ray->raydir_y;
	w_ray->line_height = (int)(g_height / w_ray->perp_wall_dist);
	w_ray->draw_start = -w_ray->line_height / 2 + g_height / 2;
	if (w_ray->draw_start < 0)
		w_ray->draw_start = 0;
	w_ray->draw_end = w_ray->line_height / 2 + g_height / 2;
	if (w_ray->draw_end >= g_height)
		w_ray->draw_end = g_height - 1;
}

static void			cal_tex(t_wall_ray *w_ray, t_info *info)
{
	w_ray->tex_num = info->map[w_ray->map_x][w_ray->map_y] - 1;
	if (w_ray->tex_num == 0)
	{
		if (w_ray->side == 0)
		{
			if (w_ray->front == 0)
				w_ray->tex_num = 2;
			else
				w_ray->tex_num = 1;
		}
		else
		{
			if (w_ray->right == 0)
				w_ray->tex_num = 4;
			else
				w_ray->tex_num = 3;
		}
	}
}

static void			set_tex(t_wall_ray *w_ray, t_info *info, int x)
{
	int				tex_x;
	double			tex_pos;
	int				tex_y;
	int				color;
	int				y;

	tex_x = (int)(w_ray->wall_x * (double)TEX_WIDTH);
	if (w_ray->side == 0 && w_ray->raydir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (w_ray->side == 1 && w_ray->raydir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	w_ray->step = 1.0 * TEX_HEIGHT / w_ray->line_height;
	tex_pos = (w_ray->draw_start - g_height / 2 \
		+ w_ray->line_height / 2) * w_ray->step;
	y = w_ray->draw_start;
	while (y < w_ray->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += w_ray->step;
		color = info->texture[w_ray->tex_num][TEX_HEIGHT * tex_y + tex_x];
		if (w_ray->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
}

void				wall_casting(t_info *info)
{
	t_wall_ray		w_ray;
	int				x;

	x = 0;
	while (x < g_width)
	{
		w_ray_init(&w_ray, info, x);
		set_wall_distance(&w_ray, info);
		dda_algorithm(&w_ray, info);
		set_draw_num(&w_ray, info);
		cal_tex(&w_ray, info);
		if (w_ray.side == 0)
			w_ray.wall_x = info->pos_y + w_ray.perp_wall_dist * w_ray.raydir_y;
		else
			w_ray.wall_x = info->pos_x + w_ray.perp_wall_dist * w_ray.raydir_x;
		w_ray.wall_x -= floor(w_ray.wall_x);
		set_tex(&w_ray, info, x);
		info->z_buffer[x] = w_ray.perp_wall_dist;
		x++;
	}
}
