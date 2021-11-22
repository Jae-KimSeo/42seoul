/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:17 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:54:19 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_bf_fd(t_list **token, int *flag)
{
	char	*ret;

	ret = NULL;
	if (((t_token *)(*token)->content)->type == CUR_BEFORE_FD)
	{
		ret = ((t_token *)((*token)->content))->value;
		*token = (*token)->next;
		*flag = 0;
	}
	if (ret == NULL)
		return (-1);
	return (ft_atoi(ret));
}

static void	check_redirect_mode(
	t_list **token, t_redirect *redirect, int bf_fd, int default_flag)
{
	if (!ft_strcmp(((t_token *)(*token)->content)->value, "<"))
		redirect->type = TYPE_REDIR_STDIN;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">"))
		redirect->type = TYPE_REDIR_STDOUT;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, "<<"))
		redirect->type = TYPE_REDIR_HEREDOC;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">>"))
		redirect->type = TYPE_REDIR_APPEND;
	if (default_flag == 1
		&& (redirect->type & (TYPE_REDIR_STDIN | TYPE_REDIR_HEREDOC)))
		redirect->before_fd = 0;
	else if (default_flag == 1
		&& (redirect->type & (TYPE_REDIR_STDOUT | TYPE_REDIR_APPEND)))
		redirect->before_fd = 1;
	else
		redirect->before_fd = bf_fd;
}

int	type_argument(t_cmd *cmd, t_list **arg, t_token *token)
{
	if (!cmd->args)
	{
		cmd->args = ft_lstnew(token->value);
		if (cmd->args == NULL)
			return (0);
		*arg = cmd->args;
	}
	else
	{
		(*arg)->next = ft_lstnew(token->value);
		if ((*arg)->next == NULL)
			return (0);
		(*arg) = (*arg)->next;
	}
	token->value = NULL;
	return (1);
}

int	type_redirect(t_AST_Node **curr, t_list **token)
{
	t_redirect	*redirect;
	int			bf_fd;
	int			default_flag;

	default_flag = 1;
	bf_fd = set_bf_fd(token, &default_flag);
	(*curr)->content = (t_redirect *)malloc(sizeof(t_redirect));
	malloc_error_check((*curr)->content);
	redirect = (*curr)->content;
	(*curr)->type = TYPE_REDIRECT;
	check_redirect_mode(token, redirect, bf_fd, default_flag);
	if ((*token)->next)
	{
		*token = (*token)->next;
		redirect->after_fd = ((t_token *)(*token)->content)->value;
		((t_token *)(*token)->content)->value = NULL;
	}
	redirect->child = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	malloc_error_check(redirect->child);
	*curr = redirect->child;
	return (1);
}
