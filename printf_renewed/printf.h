/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:12:49 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/09 11:28:46 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include<stdio.h>
#include<stdarg.h>
#include "libft/libft.h"

typedef struct			s_options
{
	int 				zero;
	int 				minus;
	int 				width;
	int 				precision;
	char 				type;
}						t_options;

char                    *check_precision(char *str, t_options set);
char                    *check_width(char *str, t_options set);
char                    *parcing_str(char *traverse, t_options *set, va_list arg);
int                     ft_printf(char* format,...);
//int                     main_process(t_options set, va_list arg);
int                     type_char(t_options *set, va_list arg);
int                     type_num(t_options *set, va_list arg);
int                     type_ptr(t_options *set, va_list arg);
int                     type_str(t_options *set, va_list arg);

#endif
