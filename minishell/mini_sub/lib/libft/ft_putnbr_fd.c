/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:04:50 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:04:51 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_positive(int n, int fd)
{
	int	mod;

	mod = n % 10;
	if (n / 10 != 0)
		ft_print_positive(n / 10, fd);
	ft_putchar_fd(mod + '0', fd);
}

static void	ft_print_negative(int n, int fd)
{
	int	mod;

	mod = (n % 10) * -1;
	if (n / 10 != 0)
		ft_print_negative(n / 10, fd);
	ft_putchar_fd(mod + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		ft_print_positive(n, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_print_negative(n, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
