#include "interpreter.h"

int main()
{
	t_list *test;

	test = interpreter("echo -n 5 < 3 | echo happy");

    print_AST((t_AST_Node *)test->content, 5);
	/*
	while (test->next)
	{
		printf("%s\n", )
	}
	*/
}