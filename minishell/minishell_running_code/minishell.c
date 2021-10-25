#include "interpreter.h"

#define t_minishell	g_shell;

typedef struct s_minishell
{
	t_list			*envp; // update t_list ->? // ->순서상관없고

	int				signal;
	int				pid;
	int				eof;
	int				read_fd;
	char			*line;
}	t_minishell;

//termios
//ctrl c, d \
// signal

int	main(int argc, char *argv[], char *envp[])
{
	t_list *AST;

	(void)argc;
	(void)argv;
	init(envp);
	while (1)
	{
		read_line();
		if (g_shell.line == NULL)
			return (PARSE_ERROR)
		AST = parse_line(g_shell.line);
		if (AST == NULL)
		{
			printf("Parsing ERROR")
			return (PARSE_ERROR);
		}

		//ft_lstclear(AST);
		execute(AST);
	}

	return (0);
}
