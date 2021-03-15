/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:32:31 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/23 14:32:37 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
