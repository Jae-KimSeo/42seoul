#include "interpreter.h"

static int	set_args(t_cmd *cmd, t_list **arg, t_token *token)
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

static int	set_redirect(t_AST_Node **curr, t_list **token)
{
	t_redirect	*redirect;

	(*curr)->content = (t_redirect *)malloc(sizeof(t_redirect));
	malloc_error_check((*curr)->content);
	redirect = (*curr)->content;
	(*curr)->type = TYPE_REDIRECT;
	if (!ft_strcmp(((t_token *)(*token)->content)->value, "<"))
		redirect->type = TYPE_REDIR_STDIN;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">"))
		redirect->type = TYPE_REDIR_STDOUT;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, "<<"))
		redirect->type = TYPE_REDIR_HEREDOC;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">>"))
		redirect->type = TYPE_REDIR_APPEND;
	*token = (*token)->next;
	redirect->after_fd = ((t_token *)(*token)->content)->value;
	((t_token *)(*token)->content)->value = NULL;
	redirect->child = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	if (redirect->child == NULL)
	malloc_error_check(redirect->child);
	*curr = redirect->child;
	return (1);
}

static int	parse_phrase(
	t_list **token,
	t_cmd **cmd,
	t_list **arg_curr,
	t_AST_Node **curr)
{
	if (((t_token *)(*token)->content)->type == CUR_CMD)
	{
		if (!ft_malloc((void **)cmd, sizeof(t_cmd)))
			return (0);
		(*cmd)->cmd = ((t_token *)(*token)->content)->value;
		((t_token *)(*token)->content)->value = NULL;
	}
	else if (((t_token *)(*token)->content)->type == CUR_ARG)
	{
		if (!set_args(*cmd, arg_curr, (*token)->content))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type == CUR_REDIRECT)
	{
		if (!set_redirect(curr, token))
			return (0);
	}
	return (1);
}

t_AST_Node	*parse_cmd(t_list **token)
{
	t_list	*arg;
	t_cmd	*cmd;
	t_AST_Node *node;
	t_AST_Node *series;

	cmd = NULL;
	node = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	malloc_error_check(node);
	series = node;
	while (*token && \
		((t_token *)(*token)->content)->type & (CUR_CMD | CUR_ARG | CUR_REDIRECT))
	{
		parse_phrase(token, &cmd, &arg, &series);
		*token = (*token)->next;
	}
	series->type = TYPE_CMD;
	series->content = cmd;
	return (node);
}
