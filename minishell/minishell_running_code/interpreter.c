#include "interpreter.h"

t_list	*interpreter(char *line)
{
	t_list	*ret;
	int		error;

	ret = lexical_analyzer(line);
	ret = parser(ret);
	error = symantic_analyzer(ret);
	if (error == 1)
	{
		free_AST(ret);
		return (SYMANTIC_ERROR)
	}
	return (ret);
}

