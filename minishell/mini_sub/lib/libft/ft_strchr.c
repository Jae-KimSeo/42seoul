/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:05:09 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:05:10 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*location;

	location = 0;
	while (*s)
	{
		if (*s == c)
		{
			location = (char *)s;
			break ;
		}
		s++;
	}
	return (location);
}
