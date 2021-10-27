#include "interpreter.h"

t_list	*syntax_analyzer(t_list *token)
{
	t_list			*AST;
	t_list			*ptr;
	t_AST_Node		*Node;

	//printf("token : %d", ((t_token *)(token->content))->type);
	Node = parse_get_node(&token); // 여기서 구조체 포인터 토큰을 왜 레퍼런스로 넘기지?
	AST = ft_lstnew(Node); // AST를 담는 리스트, 왜리스트로 만들지?
	ptr = AST;
	seriezer(token, &ptr);

	return (AST);
}


