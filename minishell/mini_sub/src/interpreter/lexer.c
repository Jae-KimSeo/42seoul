/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:54:35 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:54:37 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**skip_spaces(char **line)
{
	if (**line == '\0' || *line == NULL)
		return (NULL);
	while (**line && *line && ft_strchr(" \n\t", **line))
		(*line)++;
	return (line);
}

static t_token	*get_special_token(t_token *token, char **line, int *cur_option)
{
	token->value = get_special_item(line, cur_option);
	if (*cur_option & CUR_REDIRECT)
		token->type = CUR_REDIRECT;
	else if (*cur_option & CUR_PIPE)
		token->type = CUR_PIPE;
	return (token);
}

static t_token	*get_plain_token(t_token *token, char **line, int *cur_option)
{
	if (*cur_option & CUR_REDIRECT)
	{
		token->type = CUR_AFTER_FD;
		*cur_option ^= CUR_REDIRECT;
	}
	else if (*cur_option & CUR_CMD)
		token->type = CUR_ARG;
	else
	{
		*cur_option = CUR_CMD;
		token->type = CUR_CMD;
	}
	token->value = get_plain_item(line, cur_option, &token->type);
	if (*cur_option & CUR_BEFORE_FD)
	{
		token->type = CUR_BEFORE_FD;
		*cur_option ^= CUR_BEFORE_FD;
	}
	return (token);
}

static t_token	*set_token(char **line, int *cur_option)
{
	t_token	*token;

	line = skip_spaces(line);
	if (line == NULL || **line == '\0')
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		error(MALLOC_ERROR);
	if (ft_strchr("|<>", **line))
		token = get_special_token(token, line, cur_option);
	else
		token = get_plain_token(token, line, cur_option);
	return (token);
}

t_list	*scan_line(char **line, int *cur_option)
{
	t_list	*ret;
	t_list	*head;
	t_token	*token;

	token = set_token(line, cur_option);
	if (token == NULL)
		return (NULL);
	ret = ft_lstnew(token);
	head = ret;
	while (*line)
	{
		token = set_token(line, cur_option);
		if (token == NULL)
			break ;
		ret->next = ft_lstnew(token);
		if (ret->next == NULL)
			error(MALLOC_ERROR);
		ret = ret->next;
	}
	return (head);
}
