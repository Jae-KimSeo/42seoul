#include "interpreter.h"

t_list	*interpreter(char *line)
{
	t_list	*ret;
	int		error;

	ret = lexical_analyzer(line);
	ret = syntax_analyzer(ret);
	ret = symantic_analyzer(ret, &error);
	return (ret);
}

