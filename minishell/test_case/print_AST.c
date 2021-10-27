
#include "interpreter.h"

# define PARSE_ERROR_COUNT	5
# define PARSE_MALLOC		0
# define PARSE_MALLOC_MSG	"Memory allocation failure\n"
# define PARSE_INVAILD		1
# define PARSE_INVAILD_MSG	"invaild command\n"
# define PARSE_UNEXPECT		2
# define PARSE_UNEXPECT_MSG	"syntax error near unexpected token\n"
# define PARSE_NOTTHING		3
# define PARSE_CMD_NONE		4
# define PARSE_CMD_NONE_MSG	"command not found: "
# define PARSE_WILDCARD		5
# define PARSE_WILDCARD_MSG	"No such file or directory"

# define NO_COLOR "\e[0m"
# define TEXT_COLOR "\e[38;2;255;121;198m"
# define VALUE_COLOR "\e[38;2;189;147;249m"

# define NORMALIZE_CMD	0
# define NORMALIZE_ARG	1

/*
void	print_parse_err(t_list *err)
{
	if (err == (t_list *)PARSE_MALLOC)
		ft_putstr_fd(PARSE_MALLOC_MSG, 2);
	if (err == (t_list *)PARSE_UNEXPECT)
		ft_putstr_fd(PARSE_UNEXPECT_MSG, 2);
	if (err == (t_list *)PARSE_INVAILD)
		ft_putstr_fd(PARSE_INVAILD_MSG, 2);
}
*/

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
	printf("\tfile-> %s%s%s\n", VALUE_COLOR, redirect->after_fd, TEXT_COLOR);
	print_depth(depth);
	printf("\tAST->\n");
	if (redirect->child == NULL)
	{
		print_depth(depth);
		printf("\t%s(NULL)%s\n", VALUE_COLOR, TEXT_COLOR);
	}
	else
		print_AST(redirect->child, depth + 1);
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
	print_AST(pipe->leftchild, depth + 1);
	print_depth(depth);
	printf("\t%sright->\n", TEXT_COLOR);
	print_AST(pipe->rightchild, depth + 1);
	print_depth(depth);
	printf("}\n");
}

void	print_AST(t_AST_Node	*AST, int depth)
{
	if (AST->type == TYPE_CMD)
		print_CMD(AST->content, depth);
	else if (AST->type == TYPE_PIPE)
		print_PIPE(AST->content, depth);
	else if (AST->type == TYPE_REDIRECT)
		print_REDIRECT(AST->content, depth);
	ft_putstr_fd(NO_COLOR, 1);
}
