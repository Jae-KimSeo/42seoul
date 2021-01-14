/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:29:43 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/15 00:40:26 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char				*set_flag(char *traverse, t_options *set)
{
	while (*traverse == '-' || *traverse == '0' || *traverse == ' ')
	{
		if (*traverse == '-')
			set->minus = 1;
		if (*traverse == '0')
			set->zero = 1;
		if (*traverse == ' ')
			ft_putchar_fd(' ', 1);
		traverse++;
	}
	return (traverse);
}

static char				*set_width(char *traverse, t_options *set, va_list arg)
{
	char				*tmp_str;
	int					tmp;

	tmp = 0;
	while ((*traverse >= '0' && *traverse <= '9') || *traverse == '*')
	{
		tmp++;
		traverse++;
	}
	if (*(traverse - tmp) == '*')
		set->width = va_arg(arg, int);
	else if (tmp != 0)
	{
		if (!(tmp_str = ft_substr(traverse - tmp, 0, tmp)))
			return (NULL);
		set->width = ft_atoi(tmp_str);
		tmp_str = NULL;
		free(tmp_str);
	}
	else
		set->width = 0;
	return (traverse);
}

static char				*set_precision(char *traverse, \
		t_options *set, va_list arg)
{
	char				*tmp_str;
	int					tmp;

	tmp = 0;
	traverse++;
	while ((*traverse >= '0' && *traverse <= '9') || *traverse == '*')
	{
		tmp++;
		traverse++;
	}
	if (*(traverse - tmp) == '*')
		set->precision = va_arg(arg, int);
	else if (tmp != 0)
	{
		if (!(tmp_str = ft_substr(traverse - tmp, 0, tmp)))
			return (NULL);
		set->precision = ft_atoi(tmp_str);
		tmp_str = NULL;
		free(tmp_str);
	}
	else
		set->precision = 0;
	return (traverse);
}

static char				*set_type(char *traverse, t_options *set)
{
	char				*tmp_str;
	int					tmp;

	tmp = 0;
	if ((*traverse >= 'a' && *traverse <= 'z') || \
		(*traverse >= 'A' && *traverse <= 'Z') || *traverse == '%')
	{
		tmp++;
		traverse++;
	}
	if (tmp != 0)
	{
		if (!(tmp_str = ft_substr(traverse - tmp, 0, tmp)))
			return (NULL);
		if (tmp == 1)
			set->type = tmp_str[0];
		tmp_str = NULL;
		free(tmp_str);
	}
	return (traverse);
}

char					*parcing_str(char *traverse, \
		t_options *set, va_list arg)
{
	traverse = set_flag(traverse, set);
	traverse = set_width(traverse, set, arg);
	if (set->width < 0)
	{
		if (set->zero == 1)
			set->zero = 0;
		set->minus = 1;
		set->width *= (-1);
	}
	if (*traverse == '.')
		traverse = set_precision(traverse, set, arg);
	traverse = set_type(traverse, set);
	return (traverse);
}
