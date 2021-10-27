#include "interpreter.h"

int main()
{
	t_AST_Node *test;

	test = interpreter("echo 5 < 3 | export happy=id app tas | cat 3 < file.txt");
	

	/*
	while(test)
	{
		printf("node_type : %d\n", test->type);
		printf("left_cheild : %d right child : %d\n", ((t_pipe *)(test->content))->leftchild->type, ((t_pipe *)(test->content))->rightchild->type);
	}
	*/

	//그냥 내일 print_AST를 손봐야할듯 
	print_AST(test, 0);
	//print_CMD(((t_AST_Node *)(test->content))->content, 2);
	/*
	while (test->next)
	{
		printf("%s\n", )
	}
	*/
}