#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

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


# define NORMALIZE_CMD	0
# define NORMALIZE_ARG	1

t_list	*parse_line(char *line);
char	*parse_cmd(char *cmd);
t_list	*parse_arg(t_list *args);
char	*normalize(char **token, int type);

void	print_parse_err(t_list *err);


#endif
