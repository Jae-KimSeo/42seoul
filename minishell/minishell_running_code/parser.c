#include "interpreter.h"

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

t_list	*syntax_analyzer(t_lexer *lexer)
{
	t_list	*token;
	t_list	*AST;
	t_list	*curr;
	t_ASTNode	*Node;

	//ASTs? -> AST를 담고있는 리스트, AST는 트리겠고 트리별로 하나의 커맨드인가 ?
	//메모리할당이 어디서 이루어질지 고려해봐야되
	token = lexer->token;// lexer에서 토큰 어떻게 받으랠 ?
	AST = NULL;
	Node = syntax_AST(&token);
	AST = ft_lstnew(Node); // AST를 담는 리스트, 왜리스트로 만들지?
	curr = AST;
	if (!analyzer(token, &curr))
		return (destructor(AST, ASTs, token));
	free_token(token);
	return (AST);