#include "interpreter.h"

int main()
{
	t_list *test;

	test = interpreter("echo 5 < 3 | export happy=id app tas | cat 3 < file.txt");
	printf("test check : %d\n",(((t_AST_Node *)(test->content))->type));
	//print_CMD(((t_AST_Node *)(test->content))->content, 2);
    //print_AST(((t_AST_Node *)(test->content)), 10); // () ㅇㅣ거 붙이고 안붙이고 차이
	/*
	while (test->next)
	{
		printf("%s\n", )
	}
	*/
}