

#include "minishell.h"
#include "parse_util.h"

static	t_AST	*destructor(t_AST *result, t_cmd *cmd)
{
	if (cmd != NULL)
		free_CMD(cmd);
	free_AST(result);
	return (PARSE_MALLOC);
}

static int	set_args(t_cmd *cmd, t_list **arg, t_token *token)  // 인자를 만든다. 인자가 뭐지 ? 인자가 여러개일 경우
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

static int	set_redirect(t_AST **curr, t_list **token) // 리다이렉트도 커맨드 단에서 하네
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
	t_cmd **cmd, // 얘는 t_list 인자로 가진 cmd 저장 구조체
	t_list **arg_curr,
	t_AST **curr)
{
	if (((t_token *)(*token)->content)->type == LX_CMD) // command 일 경우 -> 그대로 넣어주면 된다.
	{
		if (!ft_malloc((void **)cmd, sizeof(t_cmd))) // ㅇㅙ 투포인터 할당? -> 그냥 값 할당인듯?
			return (0);
		(*cmd)->cmd = ((t_token *)(*token)->content)->value;  
		((t_token *)(*token)->content)->value = NULL;
	}
	else if (((t_token *)(*token)->content)->type == LX_ARG) // 인자일 경우
	{
		if (!set_args(*cmd, arg_curr, (*token)->content))
			return (0);
	}
	else if (((t_token *)(*token)->content)->type == LX_REDIRECT) // 리다이렉트 일경우
	{
		if (!set_redirect(curr, token))
			return (0);
	}
	return (1);
}

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

t_AST	*syntax_cmd(t_list **token) // 토큰 한 덩어리
{
	t_AST	*result;
	t_AST	*curr;
	t_list	*arg_curr;
	t_cmd	*cmd;

	if (!ft_malloc((void **)&result, sizeof(t_AST))) //AST  메모리할당 t_AST 의 포인터 여야 하는거 아닌가 ?
		return (PARSE_MALLOC);
	curr = result; //  AST하나
	cmd = NULL;
	while (*token && \
		((t_token *)(*token)->content)->type & (LX_CMD + LX_ARG + LX_REDIRECT)) // 토큰이 이 세가지중에 하나야여함
	{
		if (!syntax_switch(token, &cmd, &arg_curr, &curr))
			return (destructor(result, cmd));
		*token = (*token)->next;
	}
	curr->type = FT_CMD;
	curr->data = cmd;
	return (result);
}
