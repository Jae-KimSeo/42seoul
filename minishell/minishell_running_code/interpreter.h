#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <errno.h>
#include "lib/libft.h"

#define MALLOC_ERROR	1
#define PARSE_ERROR		1
#define SYMANTIC_ERROR	1
#define EXEC_ERROR		1

#define CUR_NONE		0
#define CUR_PIPE		1
#define CUR_REDIRECT	2
#define CUR_QUOTE		4
#define CUR_DQUOTE		8
#define CUR_CMD			16
#define CUR_PATH		32
#define CUR_ARG			64

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_token
{
	int		type;
	char	*value;
}					t_token;

typedef struct		s_lexer
{
	char		*line;
	t_list		*tokens;
	int			start;
	int			end;
}					t_lexer;

typedef struct		s_AST_Node
{
	int		type;
	void	*data;
}					t_AST_Node;
//t_list 를 ASTree로

typedef struct		s_cmd
{
	char	*cmd;
	t_list	*args;
}					t_cmd;



typedef struct		s_pipe
{
	t_AST_Node	*leftchild; // redirect or cmd
	t_AST_Node	*rightchild; // pipe or rediret or cmd
}					t_pipe;

typedef struct s_redirect
{
	int			type;
	t_AST_Node	*child;
	char		*file;
}	t_redirect;


