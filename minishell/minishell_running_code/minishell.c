#include "interpreter.h"

t_minishell	g_shell;



int	main(int argc, char *argv[], char *envp[])
{
	t_list *AST;

	(void)argc;
	(void)argv;
	init_minishell(envp);
	while (1)
	{
		get_line();
		if (g_shell.line == NULL)
			return (PARSE_ERROR)
		AST = parse_line(g_sh.line);
	}

	return (0);
}
