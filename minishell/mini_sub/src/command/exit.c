/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:55:22 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:55:23 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

int	is_numeric(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (1);
		idx++;
	}
	return (0);
}

static void	run_exit(t_list *args, int err_fd, int arg_count)
{
	if (g_shell.cmd_cnt == 1)
		write(err_fd, "exit\n", 5);
	if (arg_count == 0)
		exit(0);
	else if (arg_count == 1 && !is_numeric(((char *)args[0].content)))
		exit(ft_atoi(((char *)args[0].content)));
	else if (arg_count > 1 && !is_numeric(((char *)args[0].content)))
		write(err_fd, "bash: exit: too many arguments\n", 32);
	else
	{
		write(err_fd, "bash: exit: ", 13);
		write(err_fd, ((char *)args->content), \
			ft_strlen(((char *)args->content)));
		write(err_fd, ": numeric argument required\n", 29);
		exit(255);
	}
}

static int	count_args(t_list *args)
{
	int	count_args;

	count_args = 0;
	while (args)
	{
		count_args++;
		args = args->next;
	}
	return (count_args);
}

int	ft_exit(t_list *args, t_list *fd_table)
{
	int	arg_count;
	int	err_fd;

	arg_count = count_args(args);
	err_fd = search_proc_fd(fd_table, 2);
	run_exit(args, err_fd, arg_count);
	return (SUCCESS);
}
