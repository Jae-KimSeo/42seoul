/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:45 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:54:46 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_shell;

t_AST_Node	*interpreter(char *line)
{
	t_list		*tokens;
	t_AST_Node	*head;
	int			cur_option;

	cur_option = CUR_NONE;
	tokens = scan_line(&line, &cur_option);
	if (tokens == NULL)
		return (NULL);
	translate_env(tokens);
	head = syntax_analyzer(tokens);
	free_tokens(tokens);
	if (check_tree(head, 0) != SUCCESS)
	{
		destruct_AST(head);
		return (NULL);
	}
	return (head);
}
