/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:55:02 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:55:03 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

int	get_env(void)
{
	t_list	*envp;

	envp = g_shell.env_list;
	while (envp)
	{
		printf ("%s\n", (char *)(envp->content));
		envp = envp->next;
	}
	return (SUCCESS);
}
