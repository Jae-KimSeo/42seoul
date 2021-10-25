#include "minishell.h"
#include "parse_util.h"

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

static t_AST	**syntax_switch(t_list **token, t_AST **curr)
{
	if (((t_token *)(*token)->content)->type == LX_PIPE)
	{
		curr = syntax_PIPE(token, curr);
		if (curr == NULL)
			return (PARSE_MALLOC);
	}
	*curr = syntax_cmd(token);
	if (curr == NULL)
		return (PARSE_MALLOC);
	return (curr);
}

t_AST	*parse_get_node(t_list **token)
{
	t_AST	*result;
	t_AST	**curr;

	result = syntax_cmd(token);
	if (result == NULL)
		return (PARSE_MALLOC);
	curr = &result;
	while (*token && ((t_token *)(*token)->content)->type & \
		(LX_CMD + LX_REDIRECT + LX_PIPE + LX_CTR_OP))
	{
		curr = syntax_switch(token, curr);
		if (!curr)
			return (PARSE_MALLOC);
	}
	return (result);
}





