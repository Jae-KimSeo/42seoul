/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:24:54 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/11 16:00:49 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(int base, long long n)
{
	size_t	ret;

	if (n == 0)
		return (1);
	ret = 1;
	while (n >= base || n <= (base * (-1)))
	{
		n = n / base;
		ret++;
	}
	return (ret);
}

static char		*allocate_digit(int base, long long n, size_t count, char sign)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n == 0)
		*ret = 48;
	*(ret + count) = '\0';
	if (sign)
	{
		*ret = '-';
		*(ret + --count) = n % base * (-1) + 48;
		n = n / base * (-1);
	}
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

char			*ft_itoa_base(long long n, int base)
{
	size_t		count;
	char		sign;
	char		*ret;
	size_t		i;

	i = 0;
	sign = '\0';
	count = count_digit(base, n);
	if (n < 0)
	{
		sign = '-';
		count++;
	}
	ret = allocate_digit(base, n, count, sign);
	while (ret[i])
	{
		if (!(ret[i] >= 48 && ret[i] <= 57) && ret[i] != '-')
			ret[i] += 39;
		i++;
	}
	return (ret);
}
