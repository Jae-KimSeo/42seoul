
#include "minishell.h"
#include "parse_util.h"

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

void	print_CTR_OP(t_ctr_op *ctrop, int depth)
{
	print_depth(depth);
	printf("%s{ \n", TEXT_COLOR);
	print_depth(depth);
	printf("\tControl Operator\n");
	print_depth(depth);
	printf("\ttype-> \"%s%d%s\"\n", VALUE_COLOR, ctrop->type, TEXT_COLOR);
	print_depth(depth);
	printf("\t%sleft->\n", TEXT_COLOR);
	print_AST(ctrop->left, depth + 1);
	print_depth(depth);
	printf("\t%sright->\n", TEXT_COLOR);
	print_AST(ctrop->right, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_AST(t_AST	*AST, int depth)
{
	if (AST->type == FT_CMD)
		print_CMD(AST->data, depth);
	else if (AST->type == FT_PIPE)
		print_PIPE(AST->data, depth);
	else if (AST->type == FT_CTR_OP)
		print_CTR_OP(AST->data, depth);
	else if (AST->type == FT_REDIRECT)
		print_REDIRECT(AST->data, depth);
	ft_putstr_fd(NO_COLOR, 1);
}
