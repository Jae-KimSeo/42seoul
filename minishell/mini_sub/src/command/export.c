/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:55:27 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:55:29 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

void	update_env_val(t_list *env_list, char *arg)
{
	char	**env_key_val;
	char	**arg_key_val;
	int		result;

	result = 0;
	arg_key_val = ft_split(arg, '=');
	if (arg_key_val == NULL)
		error(MALLOC_ERROR);
	while (env_list && result == 0)
	{
		env_key_val = ft_split(env_list->content, '=');
		if (ft_strncmp(arg_key_val[0], env_key_val[0],
				ft_strlen(arg_key_val[0]) + 1) == 0)
		{
			free(env_list->content);
			env_list->content = ft_strdup(arg);
			if (env_list->content == NULL)
				error(MALLOC_ERROR);
			result = 1;
		}
		free_str(env_key_val);
		env_list = env_list->next;
	}
	free_str(arg_key_val);
}

int	check_dup(t_list *list, char *arg)
{
	char	**env_key_val;
	char	**arg_key_val;
	int		result;	

	arg_key_val = ft_split(arg, '=');
	result = 0;
	if (arg_key_val == NULL)
		error(MALLOC_ERROR);
	while (list && result == 0)
	{
		env_key_val = ft_split(list->content, '=');
		if (ft_strncmp(arg_key_val[0], env_key_val[0],
				ft_strlen(arg_key_val[0]) + 1) == 0)
			result = 1;
		free_str(env_key_val);
		list = list->next;
	}
	free_str(arg_key_val);
	return (result);
}

int	append_envp(char *arg)
{
	if (arg[0] == '=')
	{
		printf("bash: export: '%s': not a valid identifier\n", arg);
		return (1);
	}
	if (ft_strchr(arg, '=') != NULL)
	{
		if (check_dup(g_shell.export_list, arg))
			update_env_val(g_shell.export_list, arg);
		else
			add_to_list(arg, &g_shell.export_list);
		if (check_dup(g_shell.env_list, arg))
			update_env_val(g_shell.env_list, arg);
		else
			add_to_list(arg, &g_shell.env_list);
	}
	else
		if (check_dup(g_shell.export_list, arg) == 0)
			add_to_list(arg, &g_shell.export_list);
	return (SUCCESS);
}

int	run_export(t_list *args)
{
	int		i;
	int		len;

	i = 0;
	len = ft_lstsize(args);
	if (len == 0)
		print_export_list();
	else
	{
		while (args)
		{
			if (append_envp((char *)(args->content)) != SUCCESS)
				return (1);
			args = args->next;
		}
	}
	return (SUCCESS);
}
