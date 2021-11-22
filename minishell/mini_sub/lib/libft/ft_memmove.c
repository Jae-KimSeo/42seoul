/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:04:26 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:04:27 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return ((void *)0);
	if ((unsigned char *)dst < (unsigned char *)src)
	{
		while (index < len)
		{
			((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	else
	{
		while (index < len)
		{
			((unsigned char *)dst)[len - index - 1]
				= ((unsigned char *)src)[len - index - 1];
			index++;
		}
	}
	return (dst);
}
