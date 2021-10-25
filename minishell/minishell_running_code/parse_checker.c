#include "interpreter.h"

int	checker(t_list *curr_token, t_list **curr)
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