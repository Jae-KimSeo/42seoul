/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 17:34:35 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/01 18:45:37 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *tmp;
	char *ret;
    
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
/*
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t len_h;
    size_t len_n;
    
    i = 0;
    if (*needle == '\0' || haystack == needle)
        return ((char*)haystack);
    len_h = ft_strlen((char *)haystack);
    len_n = ft_strlen((char *)needle));
    if (len_h < len)//
        len = len_h;
    while (*haystack && len_n + i < len)
    {
        if (ft_memcmp(haystack,needle,len))
            return ((char*)haystack)
        haystack++;
        i++;
    }
    return (NULL);
}

*/
