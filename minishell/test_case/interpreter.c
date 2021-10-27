#include "interpreter.h"

t_AST_Node	*interpreter(char *line)
{
	t_list		*tokens;
	t_AST_Node	*head;

	tokens = lexical_analyzer(line);
	head = syntax_analyzer(tokens);
	//print_AST(head, 0);
	//error = symantic_analyzer(ret);
	/*
	if (error == 1)
	{
		free_AST(ret);
		return (SYMANTIC_ERROR)
	}
	*/
	return (head);
}

