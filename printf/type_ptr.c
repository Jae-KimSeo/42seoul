/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:56:36 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/15 00:58:27 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				except_case_ptr(t_options *set)
{
	if (set->zero)
		return (1);
	if (set->precision < 0)
		set->precision = -1;
	return (0);
}

static char				*padding_type_p(char *str)
{
	char				*padd;

	padd = ft_strdup("0x");
	str = ft_strjoin(padd, str);
	padd = NULL;
	free(padd);
	return (str);
}

int						type_ptr(t_options *set, va_list arg)
{
	char				*str;
	int					ret;
	unsigned long long	i;

	str = NULL;
	ret = 0;
	if (except_case_ptr(set))
		return (-1);
	i = va_arg(arg, unsigned long long);
	if (i == 0 && set->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_unsign(i, 16);
	str = check_precision(str, *set);
	str = padding_type_p(str);
	str = check_width(str, *set);
	ft_putstr_fd(str, 1);
	ret = ft_strlen(str);
	str = NULL;
	free(str);
	return (ret);
}
