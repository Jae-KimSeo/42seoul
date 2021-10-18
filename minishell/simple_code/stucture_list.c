typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_history
{
	char				*cmd;
	char				*edit_cmd;
	struct s_history	*next;
	struct s_history	*prev;
}	t_history;

typedef struct s_minishell
{
	int				signal;
	int				status;
	int				isps2;
	int				pid;
	int				eof;
	int				read_fd;
	char			*line;
	t_history		*cmd;
	t_history		*history;
	int				cmd_i;
	int				cmd_s;
	t_list			*envp;
	struct termios	term_sh;
	struct termios	term_ori;
}	t_minishell;

//after discuss 