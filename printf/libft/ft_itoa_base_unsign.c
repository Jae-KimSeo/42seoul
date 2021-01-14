/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toispre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:02:57 by toispre           #+#    #+#             */
/*   Updated: 2021/01/14 21:02:59 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(size_t base, unsigned long long n)
{
	size_t	ret;

	if (n == 0)
		return (1);
	ret = 1;
	while (n >= base)
	{
		n = n / base;
		ret++;
	}
	return (ret);
}

static char		*allocate_digit(size_t base, unsigned long long n, size_t count)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n == 0)
		*ret = 48;
	*(ret + count) = '\0';
	while (n >= base)
	{
		*(ret + count - 1) = (n % base) + 48;
		n = n / base;
		count--;
	}
	if (n != 0)
		*(ret + count - 1) = n + 48;
	return (ret);
}

char			*ft_itoa_base_unsign(unsigned long long n, size_t base)
{
	size_t		count;
	char		*ret;
	size_t		i;

	i = 0;
	count = count_digit(base, n);
	ret = allocate_digit(base, n, count);
	while (ret[i])
	{
		if (!(ret[i] >= 48 && ret[i] <= 57) && ret[i] != '-')
			ret[i] += 39;
		i++;
	}
	return (ret);
}
