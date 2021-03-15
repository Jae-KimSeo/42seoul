/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:19:27 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 16:19:31 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_wall_distance(t_wall_ray *w_ray, t_info *info)
{
	if (w_ray->raydir_x < 0)
	{
		w_ray->step_x = -1;
		w_ray->side_dist_x = (info->pos_x - w_ray->map_x) * w_ray->delta_dist_x;
	}
	else
	{
		w_ray->step_x = 1;
		w_ray->side_dist_x = (w_ray->map_x + 1.0 - info->pos_x) \
		* w_ray->delta_dist_x;
	}
	if (w_ray->raydir_y < 0)
	{
		w_ray->step_y = -1;
		w_ray->side_dist_y = (info->pos_y - w_ray->map_y) * w_ray->delta_dist_y;
	}
	else
	{
		w_ray->step_y = 1;
		w_ray->side_dist_y = (w_ray->map_y + 1.0 - info->pos_y) \
		* w_ray->delta_dist_y;
	}
}

void		dda_algorithm(t_wall_ray *w_ray, t_info *info)
{
	while (w_ray->hit == 0)
	{
		if (w_ray->side_dist_x < w_ray->side_dist_y)
		{
			w_ray->side_dist_x += w_ray->delta_dist_x;
			w_ray->map_x += w_ray->step_x;
			w_ray->side = 0;
			if (w_ray->step_x > 0)
				w_ray->front = 1;
			else
				w_ray->front = 0;
		}
		else
		{
			w_ray->side_dist_y += w_ray->delta_dist_y;
			w_ray->map_y += w_ray->step_y;
			w_ray->side = 1;
			if (w_ray->step_y > 0)
				w_ray->right = 1;
			else
				w_ray->right = 0;
		}
		if (info->map[w_ray->map_x][w_ray->map_y] == 1)
			w_ray->hit = 1;
	}
}
