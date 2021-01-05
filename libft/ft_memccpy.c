/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:55:21 by jae-kim           #+#    #+#             */
/*   Updated: 2020/12/26 12:42:30 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void * ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	void *ptr = NULL;
	size_t i = 0;

	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		if ((unsigned char)*((char*)src + i) == (unsigned char)c)
		{
			ptr = (void*)dst + i + 1;
			break;
		}
			i++;
	}
	return (ptr);
}
