/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:47 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:59:48 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_filename(int idx)
{
	char	*num_str;
	char	*filename;

	num_str = ft_itoa(idx);
	filename = ft_strjoin(".tempfile", num_str);
	free(num_str);
	return (filename);
}
