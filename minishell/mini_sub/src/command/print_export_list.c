/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:55:32 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:55:34 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

static char	*make_str(t_list *export_list)
{
	char	*temp;
	char	*value;

	temp = ft_strchr(export_list->content, '=');
	temp++;
	value = ft_strdup(temp);
	if (value == 0)
		error(MALLOC_ERROR);
	return (value);
}

void	print_export_list(void)
{
	char	**name;
	char	*value;
	t_list	*envp;

	envp = g_shell.export_list;
	while (envp)
	{
		if (ft_strchr(envp->content, '=') != NULL)
		{
			value = make_str(envp);
			name = ft_split(envp->content, '=');
			if (name == NULL)
				error(MALLOC_ERROR);
			printf("declare -x %s=\"%s\"\n", name[0], value);
			free_str(name);
			free(value);
		}
		else if (ft_strchr(envp->content, '=') == NULL)
			printf("declare -x %s\n", (char *)(envp->content));
		envp = envp->next;
	}
}
