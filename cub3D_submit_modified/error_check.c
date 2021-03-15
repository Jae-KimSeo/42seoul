/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:33:07 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/23 14:35:03 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		sub_fence_error_row_left(t_info info)
{
	int			i;
	int			j;

	i = 1;
	while (i < info.map_height - 1)
	{
		j = 0;
		while (info.map[i][j] == -1)
		{
			if (!((info.map[i - 1][j] == 1) || (info.map[i - 1][j] == -1)) \
				|| (!((info.map[i + 1][j] == 1) || (info.map[i + 1][j] == -1))))
				map_content_error();
			j++;
		}
		if (info.map[i][j] != 1)
			map_content_error();
		i++;
	}
}

static void		sub_fence_error_row_right(t_info info)
{
	int			i;
	int			j;

	i = 1;
	while (i < info.map_height - 1)
	{
		j = 0;
		while (info.map[i][info.map_width - 1 - j] == -1)
		{
			if (!((info.map[i - 1][info.map_width - 1 - j] == 1) \
				|| (info.map[i - 1][info.map_width - 1 - j] == -1)) \
				|| (!((info.map[i + 1][info.map_width - 1 - j] == 1) \
				|| (info.map[i + 1][info.map_width - 1 - j] == -1))))
				map_content_error();
			j++;
		}
		if (info.map[i][info.map_width - 1 - j] != 1)
			map_content_error();
		i++;
	}
}

static void		sub_fence_error_col_up(t_info info)
{
	int			i;
	int			j;

	j = 1;
	while (j < info.map_width - 1)
	{
		i = 0;
		while (info.map[i][j] == -1)
		{
			if (!((info.map[i][j - 1] == 1) || (info.map[i][j - 1] == -1)) \
				|| (!((info.map[i][j + 1] == 1) || (info.map[i][j + 1] == -1))))
				map_content_error();
			i++;
		}
		if (info.map[i][j] != 1)
			map_content_error();
		j++;
	}
}

static void		sub_fence_error_col_down(t_info info)
{
	int			i;
	int			j;

	j = 1;
	while (j < info.map_width - 1)
	{
		i = 0;
		while (info.map[info.map_height - 1 - i][j] == -1)
		{
			if (!((info.map[info.map_height - 1 - i][j - 1] == 1 \
				|| (info.map[info.map_height - 1 - i][j - 1] == -1)) \
				|| (!((info.map[info.map_height - 1 - i][j + 1] == 1) \
				|| (info.map[info.map_height - 1 - i][j + 1] == -1)))))
				map_content_error();
			i++;
		}
		if (info.map[info.map_height - 1 - i][j] != 1)
			map_content_error();
		j++;
	}
}

void			fence_error_check(t_info info, t_input_opt option)
{
	int j;

	j = 0;
	while (j < info.map_width)
	{
		if ((info.map[0][j] != 1 && info.map[0][j] != -1) \
			|| (info.map[info.map_height - 1][j] != 1 \
				&& info.map[info.map_height - 1][j] != -1))
		{
			printf("ERROR\n%s\n", strerror(8));
			exit(1);
		}
		j++;
	}
	sub_fence_error_row_left(info);
	sub_fence_error_row_right(info);
	sub_fence_error_col_up(info);
	sub_fence_error_col_down(info);
}
