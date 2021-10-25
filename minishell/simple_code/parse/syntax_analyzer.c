

#include "minishell.h"
#include "parse_util.h"

static void	free_token(t_list *token)
{
	t_list	*curr;

	curr = token;
	while (curr)
	{
		ft_free(((t_token *)curr->content)->value);
		ft_free(curr->content);
		token = curr;
		curr = curr->next;
		ft_free(token);
	}
}

static t_list	*destructor(t_AST *AST, t_list *ASTs, t_list *token)
{
	free_token(token);
	if (ASTs)
		ft_lstclear(&ASTs, free_AST);
	if (AST)
		free_AST(AST);
	return (PARSE_MALLOC);
}

static int	analyzer(t_list *curr_token, t_list **curr)
{
	t_AST	*AST;

	while (curr_token)
	{
		if (curr_token)
			curr_token = curr_token->next;
		if (curr_token == NULL)
			break ;
		AST = syntax_AST(&curr_token);
		(*curr)->next = ft_lstnew(AST);
		if ((*curr)->next == NULL)
			return (0);
		*curr = (*curr)->next;
	}
	return (1);
}

t_list	*syntax_analyzer(t_list *token)
{
	t_list	*curr_token;
	t_list	*ASTs;
	t_list	*curr;
	t_AST	*AST;

	//ASTs? -> AST를 담고있는 리스트, AST는 트리겠고 트리별로 하나의 커맨드인가 ?
	//메모리할당이 어디서 이루어질지 고려해봐야되
	curr_token = token;
	ASTs = NULL;
	AST = syntax_AST(&curr_token);
	if (AST == NULL)
		destructor(AST, ASTs, token);
	ASTs = ft_lstnew(AST); // AST를 담는 리스트, 왜리스트로 만들지?
	if (ASTs == NULL)
		destructor(AST, ASTs, token);
	curr = ASTs;
	if (!analyzer(curr_token, &curr))
		return (destructor(AST, ASTs, token));
	free_token(token);
	return (ASTs);
}
