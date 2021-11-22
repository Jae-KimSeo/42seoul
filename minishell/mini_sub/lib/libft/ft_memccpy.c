/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:03:31 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:03:33 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	while (index < n)
	{
		if (((unsigned char *)src)[index] == (unsigned char)c)
		{
			flag = 1;
			index++;
			break ;
		}
		index++;
	}
	if (flag)
	{
		ft_memcpy(dst, src, index);
		return (dst + index);
	}
	else
	{
		ft_memcpy(dst, src, n);
		return ((void *)0);
	}
}
