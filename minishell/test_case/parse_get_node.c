#include "interpreter.h"

t_AST_Node *init_AST_Node(int type, void *content)
{
	t_AST_Node *ret;

	ret = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	malloc_error_check(ret);
	ret->type = type;
	ret->content = content;

	return ret;
}

static t_AST_Node	**get_node_pipe(t_list **token, t_AST_Node **curr)
{
	t_AST_Node	*after_pipe;
	t_pipe		*pipe;

	*token = (*token)->next;
	after_pipe = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	malloc_error_check(after_pipe);
	pipe = (t_pipe *)malloc(sizeof(t_pipe));
	malloc_error_check(pipe);
	after_pipe->type = TYPE_PIPE;
	after_pipe->content = pipe;
	pipe->leftchild = *curr;
	*curr = after_pipe;
	return (&pipe->rightchild); // 파이프 이후의 값
}
/*
static t_AST	**syntax_PIPE(t_list **token, t_AST **curr)
{
	t_AST	*result;
	t_pipe	*pipe;

	*token = (*token)->next;
	if (!ft_malloc((void **)&result, sizeof(t_AST)))
		return (0);
	if (!ft_malloc((void **)&pipe, sizeof(t_pipe)))
	{
		free(result);
		return (0);
	}
	result->type = FT_PIPE;
	result->data = pipe;
	pipe->left = *curr;
	*curr = result;
	return (&pipe->right);
}
*/

static t_AST_Node	**parse_pipe_case(t_list **token, t_AST_Node **curr)
{
	if (((t_token *)(*token)->content)->type == CUR_PIPE)
	{
		curr = get_node_pipe(token, curr);
		malloc_error_check(curr);
	}
	*curr = parse_cmd(token);
	malloc_error_check(curr);
	return (curr);
}

t_AST_Node	*parse_get_node(t_list **token)
{
	t_AST_Node	*init_node;
	t_AST_Node	**series_node;
	
	init_node = parse_cmd(token);	
	malloc_error_check(init_node);
	series_node = &init_node;
	while (*token && ((t_token *)(*token)->content)->type & \
		(CUR_CMD | CUR_REDIRECT | CUR_PIPE))
		series_node = parse_pipe_case(token, series_node);
	return (*series_node);
}



