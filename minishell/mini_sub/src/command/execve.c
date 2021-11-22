/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:55:18 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:55:20 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

char	*find_file(char *path, char *cmd)
{
	struct dirent	*file;
	DIR				*dir_ptr;
	char			*result;

	dir_ptr = opendir(path);
	if (dir_ptr == NULL)
		return (NULL);
	file = readdir(dir_ptr);
	while (file)
	{
		if (ft_strcmp(file->d_name, cmd) == 0)
		{
			result = ft_strjoin_free(path, "/", 1);
			return (ft_strjoin(result, cmd));
		}
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	return (NULL);
}

char	*find_path(char *cmd)
{
	char	**path_list;
	char	*result;

	result = NULL;
	path_list = ft_split(get_env_str("PATH"), ':');
	while (*path_list)
	{
		result = find_file(*path_list, cmd);
		if (result != NULL)
			break ;
		path_list++;
	}
	if (result == NULL)
		return (cmd);
	return (result);
}

char	**format_cmd_str(t_cmd *cmd)
{
	char	**str;
	int		len;
	int		i;
	t_list	*curr;

	len = ft_lstsize(cmd->args);
	str = (char **)malloc(sizeof(char *) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[0] = find_path(cmd->cmd);
	i = 1;
	curr = cmd->args;
	while (i <= len)
	{
		str[i] = curr->content;
		i++;
		curr = curr->next;
	}
	str[i] = NULL;
	return (str);
}

void	run_execve(t_cmd *cmd)
{
	int		result;
	char	**str;
	char	**env;

	str = format_cmd_str(cmd);
	env = convert_list_to_arr(g_shell.export_list);
	if (str == NULL || env == NULL)
		error(MALLOC_ERROR);
	result = execve(str[0], str, env);
	write(2, "bash: ", 6);
	write(2, cmd->cmd, ft_strlen(cmd->cmd));
	if (check_dup(g_shell.export_list, "PATH") == 0)
		write(2, ": No such file or directory\n", 28);
	else
		write(2, ": command not found\n", 20);
	free_str(str);
	free_str(env);
	exit(127);
}
