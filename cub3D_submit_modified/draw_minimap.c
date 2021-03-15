/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:04:40 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 14:49:45 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_lines_1(t_info *info)
{
	int				i;
	double			x[2];
	double			y[2];

	i = 0;
	while (i < info->map_width)
	{
		x[0] = i * TILE_SIZE + g_width - (info->map_width * TILE_SIZE);
		y[0] = g_height - (info->map_height * TILE_SIZE);
		x[1] = i * TILE_SIZE + g_width - (info->map_width * TILE_SIZE);
		y[1] = g_height;
		draw_line(info, x, y);
		i++;
	}
	x[0] = info->map_width * TILE_SIZE - 1 + g_width - \
	(info->map_width * TILE_SIZE);
	y[0] = g_height - (info->map_height * TILE_SIZE);
	x[1] = info->map_width * TILE_SIZE - 1 + g_width - \
	(info->map_width * TILE_SIZE);
	y[1] = g_height;
	draw_line(info, x, y);
}

static void			draw_lines_2(t_info *info)
{
	int				j;
	double			x[2];
	double			y[2];

	j = 0;
	while (j < info->map_height)
	{
		x[0] = g_width - (info->map_width * TILE_SIZE);
		y[0] = j * TILE_SIZE + g_height - (info->map_height * TILE_SIZE);
		x[1] = g_width;
		y[1] = j * TILE_SIZE + g_height - (info->map_height * TILE_SIZE);
		draw_line(info, x, y);
		j++;
	}
	x[0] = g_width - (info->map_width * TILE_SIZE);
	y[0] = info->map_height * TILE_SIZE - 1 + g_height - \
	(info->map_height * TILE_SIZE);
	x[1] = g_width;
	y[1] = info->map_height * TILE_SIZE - 1 + g_height - \
	(info->map_height * TILE_SIZE);
	draw_line(info, x, y);
}

static void			draw_rectangle(t_info *info, int x, int y, int color)
{
	int				i;
	int				j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			info->img.data[g_width * (g_height - info->map_height * TILE_SIZE)\
				+ (y + i) * g_width + x + j +\
				(g_width - info->map_width * TILE_SIZE)] = color;
			j++;
		}
		i++;
	}
}

static void			draw_rectangles(t_info *info)
{
	int				i;
	int				j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] == 2)
				draw_rectangle(info, j, i, 0xFF0000);
			if (info->map[i][j] == 3)
				draw_rectangle(info, j, i, 0x660099);
			if (info->map[i][j] == 1)
				draw_rectangle(info, j, i, 0x996600);
			if (i == floor(info->pos_x) && j == floor(info->pos_y))
				draw_rectangle(info, j, i, 0xFF6600);
			else if (info->map[i][j] == 0)
				draw_rectangle(info, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void				draw_minimap(t_info *info)
{
	draw_rectangles(info);
	draw_lines_1(info);
	draw_lines_2(info);
}
