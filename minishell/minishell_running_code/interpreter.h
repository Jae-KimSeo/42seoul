#include <stdio.h>
#include "lib/libft.h"

#define MALLOC_ERROR	0
#define PARSE_ERROR		0

#define CUR_NONE		0
#define CUR_PIPE		1
#define CUR_REDIRECT	2
#define CUR_QUOTE		4
#define CUR_DQUOTE		8
#define CUR_CMD			16
#define CUR_PATH		32
#define CUR_ARG			64


typedef enum {
    NODE_PIPE 			= (1 << 0),
    NODE_BCKGRND 		= (1 << 1),
    NODE_SEQ 			= (1 << 2),
    NODE_REDIRECT_IN 	= (1 << 3),
    NODE_REDIRECT_OUT 	= (1 << 4),
    NODE_CMDPATH		= (1 << 5),
    NODE_ARGUMENT		= (1 << 6),
    NODE_DATA 			= (1 << 7),


	//일단 우선순위로 나열하면
	// single, double quote

	// 파이프
	// 리다이렉션
	// cmd
	// option
	// $ARG
	// arg
	// path -> 상대경로 절대 경로를 나누느냐

	// $PATH
	// %S 얘네둘 어디서하지 ?
} NodeType;
//생각해보면 파이프라인 기준으로 cmd가 앞뒤로 실행되는데 그 인자가 뒤로 넘어가야되.


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

// 여기서 lexer를 쓸까?

typedef struct s_lexer
{
	char		*line;
	t_list		*tokens;
	int			start;
	int			end;
}				t_lexer

//line은 같이 넣는걸로 하고
//start, end는 token에서 AST NODE 로 바꿀때

typedef struct	s_AST_Node
{
	int		type;
	void	*data;
}				t_AST_Node;
//t_list 를 ASTree로

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

typedef struct s_pipe
{
	t_AST_Node	*left;
	t_AST_Node	*right;
}	t_pipe;

typedef struct s_redirect
{
	int			type;
	t_AST_Node	*AST;
	char		*file;
}	t_redirect;

