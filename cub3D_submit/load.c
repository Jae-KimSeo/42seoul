/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:09:30 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 16:10:00 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int			x;
	int			y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, \
		&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
		&img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void			load_texture(t_info *info)
{
	t_img		img;

	load_image(info, info->texture[0], "images/eagle.xpm", &img);
	load_image(info, info->texture[1], info->north_tex, &img);
	load_image(info, info->texture[2], info->south_tex, &img);
	load_image(info, info->texture[3], info->west_tex, &img);
	load_image(info, info->texture[4], info->east_tex, &img);
	load_image(info, info->texture[5], info->spr_tex, &img);
	load_image(info, info->texture[6], "images/wood.xpm", &img);
	load_image(info, info->texture[7], "images/colorstone.xpm", &img);
}
