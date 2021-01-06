/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:45:19 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/06 13:10:47 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*erase_deli(char *ptr, char c)
{
	if (!*ptr)
		return (NULL);
	while (*ptr == c)
		ptr++;
	return (ptr);
}

size_t		get_count(char const *s, char c)
{
	size_t		ret;
	char		*ptr;

	ret = 0;
	if (*s == '\0')
		return (0);
	ptr = (char*)s;
	ptr = erase_deli(ptr, c);
	while (*ptr)
	{
		ret++;
		if (!(ptr = ft_strchr(ptr, c)))
			return (ret);
		ptr = erase_deli(ptr, c);
	}
	return (ret);
}

void		allocate_part(char **ret, char const *s, char c, size_t count)
{
	char		*ptr_forward;
	char		*ptr;
	char		*part;
	size_t		i;

	i = 0;
	ptr = (char *)s;
	while (i < count)
	{
		ptr = erase_deli(ptr, c);
		if (!(ptr_forward = ft_strchr(ptr, c)))
			part = ft_strdup(ptr);
		else
			part = ft_substr(s, ptr - s, ptr_forward - ptr);
		if (part == NULL)
		{
			while (i)
				free(ret[--i]);
			ret = NULL;
		}
		ret[i++] = part;
		ptr = ptr_forward;
	}
	ret[i] = 0;
}

char		**ft_split(char const *s, char c)
{
	size_t		count;
	char		**ret;

	if (s == NULL)
		return (NULL);
	count = get_count(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	allocate_part(ret, s, c, count);
	return (ret);
}
