/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:50 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:54:52 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

void	open_heredoc(int idx_cmd, char *EOF_str)
{
	int		temp_fd;
	char	*filename;
	char	*line;

	filename = format_filename(idx_cmd);
	temp_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (temp_fd == INVALID_FD)
		error(FILE_OPEN_ERROR);
	g_shell.input_mode |= INPUT_HEREDOC;
	while (1)
	{
		line = readline("> ");
		if (line == NULL \
			|| ft_strncmp(line, EOF_str, ft_strlen(EOF_str) + 1) == 0)
			break ;
		write(temp_fd, line, ft_strlen(line));
		write(temp_fd, "\n", 1);
		free(line);
	}
	g_shell.input_mode ^= INPUT_HEREDOC;
	if (line)
		free(line);
	close(temp_fd);
	free(filename);
}

int	check_tree(t_AST_Node *node, int idx_cmd)
{
	if (node->content == NULL)
	{
		write(STDERR_FILENO, \
			"bash: syntax error near unexpected token 'newline'\n", 52);
		return (PARSE_ERROR);
	}
	if (node->type == TYPE_PIPE)
	{
		if (check_tree(((t_pipe *)(node->content))->leftchild, idx_cmd))
			return (PARSE_ERROR);
		if (check_tree(((t_pipe *)(node->content))->rightchild, idx_cmd + 1))
			return (PARSE_ERROR);
	}
	else if (node->type == TYPE_REDIRECT)
	{
		if (((t_redirect *)(node->content))->type == TYPE_REDIR_HEREDOC)
		{
			open_heredoc(idx_cmd, ((t_redirect *)(node->content))->after_fd);
			((t_redirect *)(node->content))->type = TYPE_REDIR_STDIN;
			free(((t_redirect *)(node->content))->after_fd);
			((t_redirect *)node->content)->after_fd = format_filename(idx_cmd);
		}
		return (check_tree(((t_redirect *)(node->content))->child, idx_cmd));
	}
	return (SUCCESS);
}
