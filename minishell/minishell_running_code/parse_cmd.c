#include "minishell.h"
#include "parse_util.h"


// export -> 정렬하는 로직(envp)
// export something -> envp -> new list


// export :
// 인자가있을때 환경변수 추가 or update
// g_shell
// new_envp char**, t_list : check(old_envp) -> envp :update
// export
// 정렬(old envp)
// new_envp (g_shell)


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

static int	set_redirect(t_AST **curr, t_list **token)
{
	t_redirect	*redirect;

	if (!ft_malloc((void **)&(*curr)->data, sizeof(t_redirect)))
		return (0);
	redirect = (*curr)->data;
	(*curr)->type = FT_REDIRECT;
	if (!ft_strcmp(((t_token *)(*token)->content)->value, "<"))
		redirect->type = FT_FD_IN;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">"))
		redirect->type = FT_FD_OUT;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, "<<"))
		redirect->type = FT_FD_HEREDOC;
	else if (!ft_strcmp(((t_token *)(*token)->content)->value, ">>"))
		redirect->type = FT_FD_APPEND;
	*token = (*token)->next;
	redirect->file = ((t_token *)(*token)->content)->value;
	((t_token *)(*token)->content)->value = NULL;
	if (!ft_malloc((void **)&redirect->AST, sizeof(t_AST)))
		return (0);
	*curr = redirect->AST;
	return (1);
}

static int	syntax_switch(
	t_list **token,
	t_cmd **cmd,
	t_list **arg_curr,
	t_AST **curr)
{
	if (((t_token *)(*token)->content)->type == LX_CMD)
	{
		if (!ft_malloc((void **)cmd, sizeof(t_cmd)))
			return (0);
		(*cmd)->cmd = ((t_token *)(*token)->content)->value;
		((t_token *)(*token)->content)->value = NULL;
	}
	else if (((t_token *)(*token)->content)->type == LX_ARG)
	{
		if (!set_args(*cmd, arg_curr, (*token)->content))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type == LX_REDIRECT)
	{
		if (!set_redirect(curr, token))
			return (0);
	}
	return (1);
}

t_AST	*parse_cmd(t_list **token)
{
	t_AST	*result;// t_AST_Node *node;
	t_AST	*curr; // t_AST_Node *temp;
	t_list	*arg_curr; //
	t_cmd	*cmd; //
	t_AST_Node *node;

	if (!ft_malloc((void **)&result, sizeof(t_AST)))
		return (PARSE_MALLOC);

	node = (t_AST_Node *)malloc(sizeof(t_AST_Node));
	if (node == NULL)
	{
		printf("%s\n", strerror(12));
		exit(1);
	}

	temp = node;


	curr = result;
	cmd = NULL;
	while (*token && \
		((t_token *)(*token)->content)->type & (LX_CMD + LX_ARG + LX_REDIRECT))
	{
		if (!syntax_switch(token, &cmd, &arg_curr, &curr))
			return (destructor(result, cmd));
		*token = (*token)->next;
	}
	curr->type = TYPE_CMD;
	curr->data = cmd;
	return (result);
}
