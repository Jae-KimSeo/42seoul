/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:56:25 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 16:56:27 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "common.h"

# define CUR_NONE		0
# define CUR_PIPE		1
# define CUR_REDIRECT	2
# define CUR_BEFORE_FD	4
# define CUR_AFTER_FD	8
# define CUR_CMD		16
# define CUR_ARG		32
# define CUR_QUOTE		64
# define CUR_DQUOTE		128

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef struct s_pipe
{
	int			count;
	t_AST_Node	*leftchild;
	t_AST_Node	*rightchild;
}	t_pipe;

typedef struct s_redirect
{
	int			type;
	int			before_fd;
	char		*after_fd;
	t_AST_Node	*child;
}	t_redirect;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

t_AST_Node	*interpreter(char *line);
t_list		*scan_line(char **line, int *cur_option);
char		*get_special_item(char **line, int *cur_option);
char		*get_plain_item(char **line, int *cur_option, int *token_type);
t_AST_Node	*syntax_analyzer(t_list *token);
int			type_argument(t_cmd *cmd, t_list **arg, t_token *token);
int			type_redirect(t_AST_Node **curr, t_list **token);
t_AST_Node	*parse_cmd(t_list **token);
t_AST_Node	*parse_get_node(t_list **token);

void		malloc_error_check(void *item);
int			ft_malloc(void **dst, size_t size);
int			check_invalid_fd(char *word);
int			set_quote_option(char **line, int *temp_option, int *cur_option);

/*
translate_env
*/
int			translate_env(t_list *token);
char		*get_env_str(char *str);

/*
translate_home.c
*/
int			translate_home_case(int case_num, t_list *token, char *line);

/*
translate_dollar.c
*/
int			translate_dollar_case(t_list *token, char *line);

/*
check_tree.c
*/
int			check_tree(t_AST_Node *node, int idx_cmd);

#endif
