/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:29:03 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 15:29:33 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		array_free(int **two_di_array, int idx)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		free(two_di_array[i]);
		i++;
	}
	free(two_di_array);
}
