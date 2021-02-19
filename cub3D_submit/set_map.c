/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:58:56 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 15:59:41 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_dir_sub(t_info *info, char dir)
{
	if (dir == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
	else if (dir == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
}

static void		set_dir(t_info *info, char dir)
{
	if (dir == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (dir == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
	else
		set_dir_sub(info, dir);
}

static void		set_map_place(t_info *info, t_input_opt *option, \
char **ptr, int i)
{
	int			j;

	j = 0;
	while (j < option->count_map_width)
	{
		if (ptr[i][j] == '1' || ptr[i][j] == '0' || ptr[i][j] == '2')
		{
			info->map[i][j] = ptr[i][j] - 48;
			if (ptr[i][j] == '2')
				option->count_sprite += 1;
		}
		else if (ptr[i][j] == ' ')
			info->map[i][j] = -1;
		else if (ptr[i][j] == 'N' || ptr[i][j] == 'S' \
			|| ptr[i][j] == 'E' || ptr[i][j] == 'W')
		{
			info->map[i][j] = 0;
			info->pos_x = (float)i;
			info->pos_y = (float)j + 0.5;
			set_dir(info, ptr[i][j]);
		}
		else
			map_content_error();
		j++;
	}
}

void			set_map(t_info *info, t_input_opt *option, char **ptr)
{
	int			i;

	i = 0;
	while (i < option->count_map_height)
	{
		if (!(info->map[i] = (int*)malloc(sizeof(int) * \
			(option->count_map_width + 1))))
		{
			array_free(info->map, i - 1);
			return ;
		}
		info->map[i][option->count_map_width] = '\0';
		set_map_place(info, option, ptr, i);
		i++;
	}
}
