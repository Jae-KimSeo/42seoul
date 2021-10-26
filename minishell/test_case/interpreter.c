#include "interpreter.h"

t_list	*interpreter(char *line)
{
	t_lexer	*middle;
	t_list	*ret;
	int		error;

	middle = lexical_analyzer(line);
	ret = syntax_analyzer(middle);
	//error = symantic_analyzer(ret);
	/*
	if (error == 1)
	{
		free_AST(ret);
		return (SYMANTIC_ERROR)
	}
	*/
	return (ret);
}
