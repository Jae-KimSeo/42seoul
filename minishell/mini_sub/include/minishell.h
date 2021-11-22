/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:56:30 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:56:31 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <string.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "interpreter.h"
# include "pipeline.h"
# include "redirection.h"
# include "command.h"

t_minishell	g_shell;

/*
init_envp.c
*/
t_error	init_envp(char *envp[]);

/*
init_term.c
*/
t_error	set_term_mode(struct termios *term);
t_error	get_term_mode(struct termios *term);
t_error	set_nonc_mode(struct termios *term);
t_error	set_can_mode(struct termios *term);

void	redir_and_exe(int idx_cmd, t_AST_Node *node);

/*
execute_cmd.c
*/
void	execute_cmd(t_AST_Node *node, t_list *fd_table);

/*
convert_list_to_arr.c
*/
char	**convert_list_to_arr(t_list *list);
/*
sort_export_list.c
*/
void	sort_export_list(t_list **export_list);

void	free_tokens(t_list *list);
void	destruct_AST(t_AST_Node *node);

#endif
