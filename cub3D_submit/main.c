/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:48:07 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 15:48:09 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			main_loop(t_info *info)
{
	screen_casting(info);
	draw_minimap(info);
	key_update_1(info);
	key_update_2(info);
	key_update_3(info);
	return (0);
}

static void			buff_init(t_info *info)
{
	int				i;
	int				j;

	i = 0;
	if (!(info->buf = (int**)malloc(sizeof(int*) * g_height)))
		return ;
	while (i < g_height)
	{
		j = 0;
		if (!(info->buf[i] = (int*)malloc(sizeof(int) * g_width)))
		{
			array_free(info->buf, i - 1);
			return ;
		}
		while (j < g_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int			texture_init(t_info *info)
{
	int				i;
	int				j;

	if (!(info->texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	i = 0;
	while (i < 8)
	{
		j = 0;
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * \
			(TEX_HEIGHT * TEX_WIDTH))))
		{
			array_free(info->texture, i - 1);
			return (-1);
		}
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	load_texture(info);
	return (0);
}

static int			info_init(t_info *info)
{
	info->mlx = mlx_init();
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_ar_l = 0;
	info->key_ar_r = 0;
	info->key_esc = 0;
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
	buff_init(info);
	if ((texture_init(info)) != 0)
		return (-1);
	info->win = mlx_new_window(info->mlx, g_width, g_height, "mlx");
	info->img.img = mlx_new_image(info->mlx, g_width, g_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,\
					&info->img.size_l, &info->img.endian);
	return (0);
}

int					main(int argc, char *argv[])
{
	t_info			info;

	input_error_check(argc);
	cub_init(&info, argv[1]);
	if (info_init(&info) != 0)
		return (0);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
		{
			screen_shot(&info);
			exit(0);
		}
	}
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &close_window, &info);
	mlx_loop(info.mlx);
}
