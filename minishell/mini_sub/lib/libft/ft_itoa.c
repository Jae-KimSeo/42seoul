/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:02:05 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:02:06 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlength(int n)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	length;

	length = ft_getlength(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	result[length] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		while (length-- > 1)
		{
			result[length] = '0' - n % 10;
			n /= 10;
		}
	}
	else
	{
		while (length--)
		{
			result[length] = '0' + n % 10;
			n /= 10;
		}
	}
	return (result);
}
