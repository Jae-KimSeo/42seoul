/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:33:07 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/19 15:17:51 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		sub_fence_error(t_info info)
{
	int			i;
	int			j;

	i = 1;
	while (i < info.map_height - 1)
	{
		j = 0;
		while (info.map[i][j] == -1)
			j++;
		if (info.map[i][j] != 1)
		{
			printf("ERROR\n%s\n", strerror(8));
			exit(1);
		}
		j = 0;
		while (info.map[i][info.map_width - 1 - j] == -1)
			j++;
		if (info.map[i][info.map_width - 1 - j] != 1)
		{
			printf("ERROR\n%s\n", strerror(8));
			exit(1);
		}
		i++;
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
	sub_fence_error(info);
}

void			map_content_error(void)
{
	printf("ERROR\n%s\n", strerror(8));
	exit(1);
}

void			input_error_check(int argc)
{
	if (argc != 2 && argc != 3)
	{
		printf("ERROR\n%s\n", strerror(5));
		exit(1);
	}
}

void			parcing_error(void)
{
	printf("ERROR\n%s\n", strerror(5));
	exit(1);
}