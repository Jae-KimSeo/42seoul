/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 17:34:35 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/06 15:27:54 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *haystack, \
		const char *needle, size_t len)
{
	const char	*tmp;
	char		*ret;

	tmp = needle;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && *needle && len != 0)
	{
		if (*haystack == *needle)
		{
			if (needle - tmp == 0)
				ret = (char*)haystack;
			needle++;
		}
		else
			needle = tmp;
		len--;
		haystack++;
	}
	if (*needle == '\0')
		return (ret);
	else
		return (NULL);
}
