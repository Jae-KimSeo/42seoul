/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:53:56 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/19 15:14:49 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				g_width;
int				g_height;

static void		opt_init(t_input_opt *option)
{
	int			i;

	i = 0;
	option->resolution[0] = -1;
	option->resolution[1] = -1;
	option->north = NULL;
	option->south = NULL;
	option->west = NULL;
	option->east = NULL;
	option->spr = NULL;
	while (i < 3)
	{
		option->floor[i] = -1;
		option->ceil[i] = -1;
		i++;
	}
	option->count_map_height = 0;
	option->count_map_width = 0;
	option->map_str = ft_strdup("");
	option->count_sprite = 0;
}

static void		set_view(t_input_opt *option, char **ptr)
{
	input_view_error_check(ptr);
	if (ft_strncmp(ptr[0], "R", 1) == 0)
	{
		option->resolution[0] = ft_atoi(ptr[1]);
		option->resolution[1] = ft_atoi(ptr[2]);
	}
	else if (ft_strncmp(ptr[0], "NO", 2) == 0)
		option->north = ptr[1];
	else if (ft_strncmp(ptr[0], "SO", 2) == 0)
		option->south = ptr[1];
	else if (ft_strncmp(ptr[0], "WE", 2) == 0)
		option->west = ptr[1];
	else if (ft_strncmp(ptr[0], "EA", 2) == 0)
		option->east = ptr[1];
	else if (ft_strncmp(ptr[0], "S", 1) == 0)
		option->spr = ptr[1];
	else
		parcing_error();
}

static void		set_opt(t_input_opt *option, char **ptr)
{
	char		**tmp_ptr;

	if (!(ft_strncmp(ptr[0], "F", 1) == 0 || ft_strncmp(ptr[0], "C", 1) == 0))
		set_view(option, ptr);
	else
	{
		if (ptr[1] == NULL)
			input_error();
		tmp_ptr = ft_split(ptr[1], ',');
		input_color_error_check(tmp_ptr);
		if (ft_strncmp(ptr[0], "F", 1) == 0)
		{
			option->floor[0] = ft_atoi(tmp_ptr[0]);
			option->floor[1] = ft_atoi(tmp_ptr[1]);
			option->floor[2] = ft_atoi(tmp_ptr[2]);
		}
		else if (ft_strncmp(ptr[0], "C", 1) == 0)
		{
			option->ceil[0] = ft_atoi(tmp_ptr[0]);
			option->ceil[1] = ft_atoi(tmp_ptr[1]);
			option->ceil[2] = ft_atoi(tmp_ptr[2]);
		}
		free(tmp_ptr);
	}
}

static void		parcing_line(t_input_opt *option, char *line)
{
	char		**ptr;
	char		*tmp;

	if (*line == '\n' || *line == 0)
		return ;
	if (*line >= 'A' && *line <= 'Z')
	{
		ptr = ft_split(line, ' ');
		set_opt(option, ptr);
		free(ptr);
	}
	else if (*line == '1' || *line == ' ')
	{
		tmp = ft_strjoin(option->map_str, "@");
		free(option->map_str);
		option->map_str = ft_strjoin(tmp, line);
		free(tmp);
		option->count_map_height += 1;
		if (option->count_map_width == 0)
			option->count_map_width = (int)ft_strlen(line);
	}
	else
		input_error();
}

void			get_map(t_input_opt *option, char *input_file)
{
	int			fd;
	int			i;
	char		*line;

	i = 1;
	opt_init(option);
	fd = open(input_file, O_RDONLY);
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		parcing_line(option, line);
		free(line);
	}
	option_error_check(option);
	close(fd);
}
