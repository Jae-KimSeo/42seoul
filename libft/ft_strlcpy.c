/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toispre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:26:01 by toispre           #+#    #+#             */
/*   Updated: 2020/12/26 15:34:22 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t len;

	len = 0;
    if (src == NULL)
        return (0);
	while ((len < dstsize - 1) && *src && (dstsize != 0))
	{
		*dst = *src;
		src++;
		dst++;
		len++;
	}
    if (dstsize != 0)
        *dst = '\0';
	while (*(src++))
		len++;
	return (len);
}
