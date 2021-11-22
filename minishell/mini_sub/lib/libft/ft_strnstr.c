/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:14 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:06:15 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	iter;

	index = 0;
	if (needle[index] == '\0')
		return ((char *)haystack);
	while (index < len && haystack[index])
	{
		iter = 0;
		while (haystack[index + iter] == needle[iter] && index + iter < len)
		{
			iter++;
			if (needle[iter] == '\0')
				return ((char *)haystack + index);
		}
		index++;
	}
	return (0);
}
