# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toispre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 17:01:08 by toispre           #+#    #+#              #
#    Updated: 2021/01/12 17:49:36 by toispre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a 
SRCS = parcing_str.c check_precision.c check_width.c ft_printf.c type_char.c type_num.c type_ptr.c type_str.c
C_FLAG = -Wall -Wextra -Werror
LIBC = ar rc
LIBR = ranlib
LIBFT = libft.a
OBJS = ${SRCS:.c=.o}
.c.o: ${OBJS}
		${CC} ${C_FLAG} -c $< -o ${<:.c=.o}

$(NAME):  $(LIBFT) ${OBJS}
	cp ./libft/$(LIBFT) $(NAME) 
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

$(LIBFT): 
	@$(MAKE) -C ./libft all

all: $(NAME)

clean:
	@$(MAKE) -C ./libft clean
	rm -f ${OBJS}

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
