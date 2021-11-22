/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:52:12 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:52:16 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

static t_error	format_envp(char *envp, t_list **list)
{
	char	*cur_envp;
	t_list	*new;

	cur_envp = ft_strdup(envp);
	if (cur_envp == NULL)
		return (MALLOC_ERROR);
	new = ft_lstnew(cur_envp);
	if (new == NULL)
		return (MALLOC_ERROR);
	ft_lstadd_back(list, new);
	return (SUCCESS);
}

t_error	init_envp(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (format_envp(envp[i], &(g_shell.env_list)))
			return (MALLOC_ERROR);
		if (format_envp(envp[i], &(g_shell.export_list)))
			return (MALLOC_ERROR);
		i++;
	}
	sort_export_list(&(g_shell.export_list));
	return (SUCCESS);
}
