#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <errno.h>
#include "lib/libft/libft.h"

#define MALLOC_ERROR	1
#define PARSE_ERROR		1
#define SYMANTIC_ERROR	1
#define EXEC_ERROR		1

#define CUR_NONE		0
#define CUR_PIPE		1
#define CUR_REDIRECT	2
#define CUR_AFTER_FD	4
#define CUR_CMD			8
#define CUR_ARG			16
#define CUR_QUOTE		32
#define CUR_DQUOTE		64

#define TYPE_PIPE 		 	0
#define TYPE_REDIRECT		1
#define	TYPE_CMD 			2
#define	TYPE_ARG  			4
#define	TYPE_REDIR_STDIN	8
#define	TYPE_REDIR_STDOUT	16
#define	TYPE_REDIR_HEREDOC	32
#define	TYPE_REDIR_APPEND	64


	/*enum과 define차이
typedef enum type
{
	TYPE_PIPE = 0,
	TYPE_REDIRECT = 1,
	TYPE_CMD = 2,
	TYPE_ARG = 4,
	TYPE_REDIR_STDIN = 8,
	TYPE_REDIR_STDOUT = 16,
	TYPE_REDIR_HEREDOC = 32,
	TYPE_REDIR_APPEND = 64
}TYPE;
*/
/*
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/
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
	void	*content;
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
	char		*after_fd;
}	t_redirect;


t_list			*interpreter(char *line);
t_list			*lexical_analyzer(char *line);
char			*get_special_item(char **line, int *cur_option);
char			*get_plain_item(char **line);
t_list			*syntax_analyzer(t_list *token);
t_AST_Node		*parse_cmd(t_list **token);
t_AST_Node		*parse_get_node(t_list **token);
int				seriezer(t_list *token, t_list **curr);
void			print_AST(t_AST_Node	*AST, int depth);

int				ft_malloc(void **dst, size_t size);
char			*ft_strappendc(char *str, char c);
void			malloc_error_check(void *item);
void			*ft_free_ret(void *target, void *ret);

void	print_AST(t_AST_Node	*AST, int depth);
void	print_CMD(t_cmd *cmd, int depth);