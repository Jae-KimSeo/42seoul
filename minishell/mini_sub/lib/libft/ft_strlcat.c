/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:05:47 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:05:48 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	iter;
	size_t	length;

	iter = 0;
	length = 0;
	while (dst[length])
		length++;
	while (src[iter] && iter + length + 1 < dstsize)
	{
		dst[length + iter] = src[iter];
		iter++;
	}
	dst[iter + length] = '\0';
	while (src[iter])
		iter++;
	if (length > dstsize)
		return (dstsize + iter);
	else
		return (length + iter);
}
