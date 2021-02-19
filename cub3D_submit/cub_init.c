/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:04:23 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 16:04:26 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			memory_init(t_info *info, t_input_opt *option)
{
	if (option->resolution[0] > MAX_WIDTH)
		g_width = MAX_WIDTH;
	else
		g_width = option->resolution[0];
	if (option->resolution[1] > MAX_HEIGHT)
		g_height = MAX_HEIGHT;
	else
		g_height = option->resolution[1];
	if (!(info->z_buffer = (double*)malloc(sizeof(double) * g_width)))
		return ;
	if (!(info->map = (int**)malloc(sizeof(int*) * \
		(option->count_map_height + 1))))
		return ;
	info->map[option->count_map_height] = NULL;
}

static void			num_init(t_info *info, t_input_opt option)
{
	unsigned int	color;

	color = 0xFFFFFF;
	info->map_height = option.count_map_height;
	info->map_width = option.count_map_width;
	info->north_tex = option.north;
	info->south_tex = option.south;
	info->west_tex = option.west;
	info->east_tex = option.east;
	color = (color & (option.floor[0] << 16)) \
	| (color & (option.floor[1] << 8)) \
	| (color & (option.floor[2]));
	info->floor_rgb = color;
	color = 0xFFFFFF;
	color = (color & (option.ceil[0] << 16)) | (color & (option.ceil[1] << 8)) \
	| (color & (option.ceil[2]));
	info->ceil_rgb = color;
	info->num_sprites = option.count_sprite;
}

static void			set_sprite(t_info *info, t_input_opt option)
{
	int				i;
	int				j;
	int				n;

	i = 0;
	n = 0;
	if (!(g_sprite = (struct s_sprite *)malloc(sizeof(struct s_sprite) * \
		info->num_sprites)))
		return ;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			if (info->map[i][j] == 2)
			{
				g_sprite[n].x = (float)i + 0.5;
				g_sprite[n].y = (float)j + 0.5;
				g_sprite[n].texture = 5;
				n++;
			}
			j++;
		}
		i++;
	}
}

void				cub_init(t_info *info, char *input_file)
{
	char			**ptr;
	t_input_opt		option;

	get_map(&option, input_file);
	memory_init(info, &option);
	ptr = ft_split(option.map_str, '@');
	set_map(info, &option, ptr);
	num_init(info, option);
	set_sprite(info, option);
	info->spr_tex = option.spr;
	fence_error_check(*info, option);
	free(ptr);
}
