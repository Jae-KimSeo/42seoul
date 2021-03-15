/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:16:24 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/19 15:24:53 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				input_error(void)
{
	printf("ERROR\n%s\n", strerror(22));
	exit(1);
}

void				input_color_error_check(char **ptr)
{
	int				i;
	int				tmp;

	i = 0;
	while (i < 3)
	{
		if (!(ptr[i]))
			input_error();
		tmp = ft_atoi(ptr[i]);
		if (tmp > 256 || tmp < 0)
			input_error();
		i++;
	}
}

void				input_view_error_check(char **ptr)
{
	if (ft_strncmp(ptr[0], "R", 1) == 0)
	{
		if (!ptr[1] || !ptr[2])
			input_error();
	}
	else if ((ft_strncmp(ptr[0], "NO", 2) == 0) \
			|| (ft_strncmp(ptr[0], "SO", 2) == 0) \
			|| (ft_strncmp(ptr[0], "WE", 2) == 0) \
			|| (ft_strncmp(ptr[0], "EA", 2) == 0) \
			|| (ft_strncmp(ptr[0], "S", 1) == 0))
	{
		if (!ptr[1] || ptr[2])
			input_error();
	}
}

static void			option_error(void)
{
	printf("ERROR\n%s\n", strerror(22));
	exit(1);
}

void				option_error_check(t_input_opt *option)
{
	int				i;

	i = 0;
	if (option->resolution[0] == -1 || option->resolution[1] == -1 \
		|| option->north == NULL || option->south == NULL \
		|| option->west == NULL || option->east == NULL || option->spr == NULL)
		option_error();
	while (i < 3)
	{
		if (option->floor[i] == -1 || option->ceil[i] == -1)
			option_error();
		i++;
	}
	if (option->count_map_height == 0 || option->count_map_width == 0)
		option_error();
}
