#include "interpreter.h"



t_list	*interpreter(char *line)
{
	t_list	*ret;

	ret = lexical_analyzer(line);
	ret = syntax_analyzer(ret);
	return (ret);
}

