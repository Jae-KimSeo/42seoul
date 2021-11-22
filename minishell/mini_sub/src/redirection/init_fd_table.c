/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:59 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:00:00 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_fd_table_valid(t_list *fd_table, int len)
{
	int	count;

	count = 0;
	while (fd_table)
	{
		if (fd_table->content == NULL)
			return (0);
		count++;
		fd_table = fd_table->next;
	}
	if (count != len)
		return (0);
	return (1);
}

t_list	*init_fd_table(void)
{
	t_list	*fd_table;

	fd_table = ft_lstnew(fd_new(0, dup(STDIN_FILENO)));
	ft_lstadd_back(&fd_table, ft_lstnew(fd_new(1, dup(STDOUT_FILENO))));
	ft_lstadd_back(&fd_table, ft_lstnew(fd_new(2, dup(STDERR_FILENO))));
	if (is_fd_table_valid(fd_table, 3) == 0)
	{
		ft_lstclear(&fd_table, free);
		return (NULL);
	}
	return (fd_table);
}
