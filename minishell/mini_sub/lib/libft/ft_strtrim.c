/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:25 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:06:26 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isset(char const c, char const *set)
{
	size_t	iter;

	iter = 0;
	while (set[iter])
	{
		if (c == set[iter])
			return (1);
		iter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	result = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_isset(s1[start], set))
		start++;
	if (start == end + 1)
		return (result = ft_strdup(""));
	while (ft_isset(s1[end], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (0);
	ft_strlcpy(result, (char *)(s1 + start), end - start + 2);
	return (result);
}
