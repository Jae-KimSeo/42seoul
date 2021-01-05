/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:59:39 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/01 23:08:03 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(const char *str)
{
	long long sum;
    int sign;
    int count;

	sum = 0;
    count = 0;
    sign = 1;
    while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = (-1) * sign;
        str++;
    }
	while (*str >= 48 && *str <= 57)
	{
		sum = sum * 10 + *str - 48;
		str++;
        count++;
	}
    sum *= sign;
    if (sign == 1 && count > 20)
        return (-1);
    if (sign == -1 && count > 20)
        return (0);
	return (sum);
}
