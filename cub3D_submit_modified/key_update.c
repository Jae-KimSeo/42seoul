/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:17:58 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 15:18:31 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		key_update_1(t_info *info)
{
	if (info->key_w)
	{
		if (info->map[(int)(info->pos_x + info->dir_x \
					* info->move_speed)][(int)(info->pos_y)] != 1)
			info->pos_x += info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_x)][(int)(info->pos_y \
					+ info->dir_y * info->move_speed)] != 1)
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (info->key_s)
	{
		if (info->map[(int)(info->pos_x - \
			info->dir_x * info->move_speed)][(int)(info->pos_y)] != 1)
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_x)][(int)(info->pos_y \
			- info->dir_y * info->move_speed)] != 1)
			info->pos_y -= info->dir_y * info->move_speed;
	}
}

void		key_update_2(t_info *info)
{
	if (info->key_a)
	{
		if (info->map[(int)(info->pos_x + info->dir_y \
			* info->move_speed)][(int)(info->pos_y)] != 1)
			info->pos_x += info->dir_y * info->move_speed;
		if (info->map[(int)(info->pos_x)][(int)(info->pos_y \
			+ info->dir_x * info->move_speed)] != 1)
			info->pos_y += info->dir_x * info->move_speed;
	}
	if (info->key_d)
	{
		if (info->map[(int)(info->pos_x - info->dir_y \
			* info->move_speed)][(int)(info->pos_y)] != 1)
			info->pos_x -= info->dir_y * info->move_speed;
		if (info->map[(int)(info->pos_x)][(int)(info->pos_y \
			- info->dir_x * info->move_speed)] != 1)
			info->pos_y -= info->dir_x * info->move_speed;
	}
}

static void	key_update_3_sub(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_ar_l)
	{
		old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) \
			- info->dir_y * sin(info->rot_speed);
		info->dir_y = old_dir_x * sin(info->rot_speed) \
			+ info->dir_y * cos(info->rot_speed);
		old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) \
			- info->plane_y * sin(info->rot_speed);
		info->plane_y = old_plane_x * sin(info->rot_speed) \
			+ info->plane_y * cos(info->rot_speed);
	}
}

void		key_update_3(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_ar_r)
	{
		old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) \
			- info->dir_y * sin(-info->rot_speed);
		info->dir_y = old_dir_x * sin(-info->rot_speed) \
			+ info->dir_y * cos(-info->rot_speed);
		old_plane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) \
			- info->plane_y * sin(-info->rot_speed);
		info->plane_y = old_plane_x * sin(-info->rot_speed) \
			+ info->plane_y * cos(-info->rot_speed);
	}
	key_update_3_sub(info);
	if (info->key_esc)
		exit(0);
}
