/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:56:05 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 14:56:52 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				draw_line(t_info *info, double *x, double *y)
{
	double			delta_x;
	double			delta_y;
	double			step;

	delta_x = x[1] - x[0];
	delta_y = y[1] - y[0];
	step = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	delta_x /= step;
	delta_y /= step;
	while (fabs(x[1] - x[0]) > 0.01 || fabs(y[1] - y[0]) > 0.01)
	{
		info->img.data[(int)floor(y[0]) * g_width + \
			(int)floor(x[0])] = 0xb3b3b3;
		x[0] += delta_x;
		y[0] += delta_y;
	}
}
