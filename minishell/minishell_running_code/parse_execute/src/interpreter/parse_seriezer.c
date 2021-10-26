#include "interpreter.h"

int	seriezer(t_list *token, t_list **curr)
{
	t_AST_Node	*node;

	while (token)
	{
		if (token)
			token = token->next;
		if (token == NULL)
			break ;
		node = parse_get_node(&token);
		(*curr)->next = ft_lstnew(node);
		malloc_error_check((*curr)->next);
		*curr = (*curr)->next;
	}
	return (1);
}