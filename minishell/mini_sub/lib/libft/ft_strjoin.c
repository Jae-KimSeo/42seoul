/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:05:40 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:05:41 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	length;
	size_t	iter;
	char	*result;

	if (!s1 || !s2)
		return (0);
	index = 0;
	iter = 0;
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(length);
	if (!result)
		return (0);
	while (s1[iter])
		result[index++] = s1[iter++];
	iter = 0;
	while (s2[iter])
		result[index++] = s2[iter++];
	result[index] = '\0';
	return (result);
}
