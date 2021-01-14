/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:21:31 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/14 21:25:51 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_options		init_option(void)
{
    t_options			ret;

	ret.minus = 0;
	ret.zero = 0; 
	ret.width = 0;
	ret.precision = -1;
	ret.type = 0;
	return (ret);
}

static int				print_one_set(t_options *set, va_list arg)
{
	int					temp_len;

	if (set->type == 'd' || set->type == 'i' || set->type == 'u' || \
		set->type == 'u' || set->type == 'x' || set->type == 'X')
		temp_len = type_num(set, arg);
	else if (set->type == 's')
		temp_len = type_str(set, arg);
	else if (set->type == 'c' || set->type == '%')
		temp_len = type_char(set, arg);
	else if (set->type == 'p')
		temp_len = type_ptr(set, arg);
	else
		temp_len = -1;
	return (temp_len);
}

int						ft_printf(char* format,...)
{
    char				*traverse;
    t_options			set;
    va_list				arg;
    int					sum_len;
    int					temp_len;
 
	traverse = format;
	va_start(arg, format);
	sum_len = 0;
	while (*traverse)
	{
		while (*traverse != '%' && *traverse)
		{
			ft_putchar_fd(*traverse, 1);
			sum_len++;
			traverse++;
		}
		if (!*traverse)
			break ;
		traverse++;
		set = init_option();
		traverse = parcing_str(traverse, &set, arg);
		temp_len = print_one_set(&set, arg);
		if (temp_len != -1)
			sum_len += temp_len;
		else
			return (0);
	}
	va_end(arg);
	return (sum_len);
}

