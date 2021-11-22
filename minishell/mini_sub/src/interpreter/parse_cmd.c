/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:28 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:54:31 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_phrase(
	t_list **token, t_cmd **cmd, t_list **arg_curr, t_AST_Node **curr)
{
	if (((t_token *)(*token)->content)->type & CUR_CMD)
	{
		if (!ft_malloc((void **)cmd, sizeof(t_cmd)))
			return (0);
		(*cmd)->cmd = ((t_token *)(*token)->content)->value;
		((t_token *)(*token)->content)->value = NULL;
	}
	else if (((t_token *)(*token)->content)->type & CUR_ARG)
	{
		if (!type_argument(*cmd, arg_curr, (*token)->content))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type
		& (CUR_REDIRECT | CUR_BEFORE_FD))
	{
		if (!type_redirect(curr, token))
			return (0);
	}
	return (1);
}

t_AST_Node	*parse_cmd(t_list **token)
{
	t_list		*arg;
	t_cmd		*cmd;
	t_AST_Node	*node;
	t_AST_Node	*series;

	cmd = NULL;
	node = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	if (node == NULL)
		error(MALLOC_ERROR);
	series = node;
	while (*token && ((t_token *)(*token)->content)->type
		& (CUR_CMD | CUR_ARG | CUR_BEFORE_FD | CUR_REDIRECT))
	{
		parse_phrase(token, &cmd, &arg, &series);
		*token = (*token)->next;
	}
	series->type = TYPE_CMD;
	series->content = cmd;
	return (node);
}
