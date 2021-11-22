/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:53:35 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:53:36 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_error_check(void *item)
{
	if (item == NULL)
		error(MALLOC_ERROR);
}

int	ft_malloc(void **dst, size_t size)
{
	*dst = ft_calloc(size, 1);
	if (*dst == NULL)
		return (0);
	return (1);
}

int	check_invalid_fd(char *word)
{
	char	*ptr;
	int		num;

	if (word == NULL)
		error(MALLOC_ERROR);
	ptr = word;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			return (0);
		}
		ptr++;
	}
	ptr = word;
	num = ft_atoi(ptr);
	if (num <= 255 && num >= 0)
		return (1);
	return (0);
}

int	set_quote_option(char **line, int *temp_option, int *cur_option)
{
	if (!ft_strncmp("'", *line, 1) && !(*temp_option & CUR_DQUOTE))
	{
		if (*temp_option & CUR_QUOTE)
		{
			*temp_option ^= CUR_QUOTE;
			*cur_option |= CUR_QUOTE;
		}
		else
			*temp_option |= CUR_QUOTE;
		return (1);
	}
	else if (!ft_strncmp("\"", *line, 1) && !(*temp_option & CUR_QUOTE))
	{
		if (*temp_option & CUR_DQUOTE)
		{
			*temp_option ^= CUR_DQUOTE;
			*cur_option |= CUR_DQUOTE;
		}
		else
			*temp_option |= CUR_DQUOTE;
		return (1);
	}
	return (0);
}
