# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plee <plee@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 17:00:51 by plee              #+#    #+#              #
#    Updated: 2021/11/19 17:00:53 by plee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -f

LIBFT_DIR			=	lib/libft/
LIBFT_FLAG			= 	-lft

READLINE_INC_DIR	=	 /Users/jae-kim/.brew/opt/readline/include
READLINE_LIB_DIR	=	 /Users/jae-kim/.brew/opt/readline/lib
READLINE_FLAG		=	-lreadline

INCLUDE_DIR			=	./include

INTER_SRC_DIR		=	./src/interpreter/
INTER_SRCS			=	check_tree.c\
						destruct_AST.c\
						interpreter.c\
						lexer_get_item.c\
						lexer.c\
						parse_cmd.c\
						parse_get_node.c\
						parse_type_check.c\
						parser.c\
						util.c\
						translate_dollar.c\
						translate_env.c\
						translate_home.c
INTER_OBJS			=	$(addprefix $(INTER_SRC_DIR), $(INTER_SRCS:.c=.o))

PIPE_SRC_DIR		=	./src/pipeline/
PIPE_SRCS			=	pipeline_utils.c\
						pipeline.c
PIPE_OBJS			=	$(addprefix $(PIPE_SRC_DIR), $(PIPE_SRCS:.c=.o))

REDIR_SRC_DIR		=	./src/redirection/
REDIR_SRCS			=	fd_new.c\
						format_filename.c\
						handle_redir.c\
						init_fd_table.c\
						redirect.c\
						search_proc_fd.c
REDIR_OBJS			=	$(addprefix $(REDIR_SRC_DIR), $(REDIR_SRCS:.c=.o))

COMMAND_SRC_DIR		=	./src/command/
COMMAND_SRCS		=	cd.c\
						env.c\
						execve.c\
						exit.c\
						export.c\
						print_export_list.c\
						pwd.c\
						unset.c\
						utils.c
COMMAND_OBJS		=	$(addprefix $(COMMAND_SRC_DIR), $(COMMAND_SRCS:.c=.o))

SRC_DIR				=	src/
SRCS				=	error.c\
						execute_cmd.c\
						init_envp.c\
						init_term.c\
						minishell.c\
						redir_and_exe.c\
						sort_export_list.c\
						convert_list_to_arr.c
OBJS				=	$(addprefix $(SRC_DIR), $(SRCS:.c=.o))

.c.o :
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(READLINE_INC_DIR) -I $(LIBFT_DIR) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(INTER_OBJS) $(PIPE_OBJS) $(REDIR_OBJS) $(COMMAND_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) -L $(LIBFT_DIR) -L $(READLINE_LIB_DIR) $(LIBFT_FLAG) $(READLINE_FLAG) $^
	

all : $(NAME)

clean :
	$(RM) $(OBJS) $(INTER_OBJS) $(PIPE_OBJS) $(REDIR_OBJS) $(COMMAND_OBJS)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all



.PHONY : all clean fclean re test
