#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/ioctl.h>

# define PARSE_ARG_ERR	1

# define DUP_ERROR		-1
# define MALLOC_FAIL	-2
# define OPEN_FAIL		-3

# define SUCCESS	0
# define FAIL		-1

# define PATH_MAX   2O

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_cd(t_list *args);

#endif