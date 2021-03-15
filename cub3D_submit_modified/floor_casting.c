/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:18:27 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/23 14:37:33 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			set_ray_var(t_ray *ray, t_info *info)
{
	ray->ray_dir_x0 = info->dir_x - info->plane_x;
	ray->ray_dir_y0 = info->dir_y - info->plane_y;
	ray->ray_dir_x1 = info->dir_x + info->plane_x;
	ray->ray_dir_y1 = info->dir_y + info->plane_y;
}

static float		get_row_d(int y)
{
	int				p;
	float			pos_z;
	float			row_distance;

	p = y - g_height / 2;
	pos_z = 0.5 * g_height;
	row_distance = pos_z / p;
	return (row_distance);
}

static void			set_tex_color(t_info *info, int floor_pattern, \
		int loop[2], int t[2])
{
	int				floor_texture;
	int				ceiling_texture;
	int				color;

	if (floor_pattern == 0)
		floor_texture = 5;
	else
		floor_texture = 7;
	ceiling_texture = 6;
	if (floor_pattern == 0 && info->floor_rgb != -1)
		color = info->floor_rgb;
	else
		color = info->texture[floor_texture][TEX_WIDTH * t[1] + t[0]];
	color = (color >> 1) & 8355711;
	info->buf[loop[1]][loop[0]] = color;
	if (info->ceil_rgb != -1)
		color = info->ceil_rgb;
	else
		color = info->texture[ceiling_texture][TEX_WIDTH * t[1] + t[0]];
	color = (color >> 1) & 8355711;
	info->buf[g_height - loop[1] - 1][loop[0]] = color;
}

static void			floor_horizon_casting(t_info *info, float floor_x, \
		float floor_y, int loop[2])
{
	int				cell_x;
	int				cell_y;
	int				t[2];
	int				floor_pattern;
	int				tmp_tex_h;

	tmp_tex_h = TEX_HEIGHT;
	cell_x = (int)(floor_x);
	cell_y = (int)(floor_y);
	t[0] = (int)(TEX_WIDTH * (floor_x - cell_x)) & (TEX_WIDTH - 1);
	t[1] = (int)(tmp_tex_h * (floor_y - cell_y)) & (tmp_tex_h - 1);
	floor_pattern = (int)((cell_x + cell_y) & 1);
	set_tex_color(info, floor_pattern, loop, t);
}

void				floor_casting(t_info *info)
{
	int				loop[2];
	t_ray			ray;
	float			floor_x;
	float			floor_y;
	float			row_distance;

	set_ray_var(&ray, info);
	loop[1] = 0;
	while (loop[1] < g_height)
	{
		row_distance = get_row_d(loop[1]);
		floor_x = info->pos_x + row_distance * ray.ray_dir_x0;
		floor_y = info->pos_y + row_distance * ray.ray_dir_y0;
		loop[0] = 0;
		while (loop[0] < g_width)
		{
			floor_horizon_casting(info, floor_x, floor_y, loop);
			floor_x += row_distance * (ray.ray_dir_x1 - ray.ray_dir_x0) \
					/ g_width;
			floor_y += row_distance * (ray.ray_dir_y1 - ray.ray_dir_y0) \
					/ g_width;
			loop[0]++;
		}
		++loop[1];
	}
}
