#include "interpreter.h"

#define TYPE_PIPE 1
#define TYPE_REDIRECT 2
#define TYPE_CMD	4
#define TYPE_ARG	8


t_list	*syntax_anlayzer(t_lexer *lexer)
{
	t_list			*token;
	t_list			*AST;
	t_list			*curr;
	t_ASTNode		*Node;

	//메모리할당이 어디서 이루어질지 고려해
	token = lexer->token;// lexer에서 토큰 어떻게 받을지
	AST = NULL;
	Node = parse_get_node(&token);
	AST = ft_lstnew(Node); // AST를 담는 리스트, 왜리스트로 만들지?
	curr = AST;
	checker(token, &curr);

	return (AST);