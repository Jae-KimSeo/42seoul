/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:53:54 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:53:57 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_AST_Node	*syntax_analyzer(t_list *token)
{
	t_AST_Node	*node;

	node = parse_get_node(&token);
	return (node);
}
