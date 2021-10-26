
#include "interpreter.h"

void	print_parse_err(t_list *err)
{
	if (err == (t_list *)PARSE_MALLOC)
		ft_putstr_fd(PARSE_MALLOC_MSG, 2);
	if (err == (t_list *)PARSE_UNEXPECT)
		ft_putstr_fd(PARSE_UNEXPECT_MSG, 2);
	if (err == (t_list *)PARSE_INVAILD)
		ft_putstr_fd(PARSE_INVAILD_MSG, 2);
}

void	print_depth(int depth)
{
	while (depth--)
		printf("\t");
}

void	print_REDIRECT(t_redirect *redirect, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tredirect-> %s%d%s\n", VALUE_COLOR, redirect->type, TEXT_COLOR);
	print_depth(depth);
	printf("\tfile-> %s%s%s\n", VALUE_COLOR, redirect->file, TEXT_COLOR);
	print_depth(depth);
	printf("\tAST->\n");
	if (redirect->AST == NULL)
	{
		print_depth(depth);
		printf("\t%s(NULL)%s\n", VALUE_COLOR, TEXT_COLOR);
	}
	else
		print_AST(redirect->AST, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_CMD(t_cmd *cmd, int depth)
{
	t_list	*curr;

	if (cmd == NULL)
		return ;
	curr = cmd->args;
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tcmd -> \"%s%s%s\"\n", VALUE_COLOR, cmd->cmd, TEXT_COLOR);
	print_depth(depth);
	printf("\targs -> \n");
	while (curr)
	{
		print_depth(depth);
		printf("\t\"%s%s%s\"\n", VALUE_COLOR, (char *)curr->content, TEXT_COLOR);
		curr = curr->next;
	}
	print_depth(depth);
	printf("}\n");
}

void	print_PIPE(t_pipe *pipe, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tPIPE\n");
	print_depth(depth);
	printf("\t%sleft->\n", TEXT_COLOR);
	print_AST(pipe->left, depth + 1);
	print_depth(depth);
	printf("\t%sright->\n", TEXT_COLOR);
	print_AST(pipe->right, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_AST(t_AST_Node	*AST, int depth)
{
	if (AST->type == FT_CMD)
		print_CMD(AST->data, depth);
	else if (AST->type == FT_PIPE)
		print_PIPE(AST->data, depth);
	else if (AST->type == FT_REDIRECT)
		print_REDIRECT(AST->data, depth);
	ft_putstr_fd(NO_COLOR, 1);
}
