/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:56:32 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/19 22:56:36 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t				ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len;

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

char				*ft_strdup(const char *s1)
{
	char			*ptr;
	char			*ret;
	size_t			len;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ret = ptr;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = '\0';
	return (ret);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	size_t			len1;
	size_t			len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy(ptr, s1, len1 + 1);
	ft_strlcpy(ptr + len1, s2, len2 + 1);
	return (ptr);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	count;
	int				i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(s + count))
	{
		if (count == start)
		{
			ft_strlcpy(ret, s + count, len + 1);
			break ;
		}
		count++;
	}
	return (ret);
}
