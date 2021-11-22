/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_proc_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:00:14 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:00:17 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_proc_fd(t_list *fd_table, int shell_fd)
{
	t_list	*curr;

	curr = fd_table;
	while (curr)
	{
		if (((t_fd *)curr->content)->fd_shell == shell_fd)
			return (((t_fd *)curr->content)->fd_proc);
		curr = curr->next;
	}
	return (INVALID_FD);
}
