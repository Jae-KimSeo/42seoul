/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:21:25 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 16:22:59 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw(t_info *info)
{
	int			x;
	int			y;

	y = 0;
	while (y < g_height)
	{
		x = 0;
		while (x < g_width)
		{
			if (x < g_width - info->map_width * TILE_SIZE \
			|| y < g_height - info->map_height * TILE_SIZE)
				info->img.data[y * g_width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void			screen_casting(t_info *info)
{
	floor_casting(info);
	wall_casting(info);
	sprite_casting(info);
	draw(info);
}

void			screen_shot(t_info *info)
{
	screen_casting(info);
	draw_minimap(info);
	save_bmp(info);
}
