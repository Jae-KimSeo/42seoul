/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_to_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:52:43 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:52:44 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_list(t_list *list)
{
	int	result;

	result = 0;
	while (list)
	{
		result++;
		list = list->next;
	}
	return (result);
}

char	**convert_list_to_arr(t_list *list)
{
	char	**result;
	int		list_count;
	int		idx;

	idx = 0;
	list_count = count_list(list);
	result = (char **)malloc(sizeof(char *) * (list_count + 1));
	if (result == NULL)
		error(MALLOC_ERROR);
	result[list_count] = NULL;
	while (list)
	{
		result[idx] = ft_strdup((char *)list->content);
		list = list->next;
		idx++;
	}
	return (result);
}
