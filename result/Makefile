CC = gcc
NAME=push_swap
SRCS = algorithm_main.c al_b_one_piv_sub.c link_list.c algorithm_a_to_b.c algorithm_a_to_b_one_pivot.c algorithm_b_to_a.c algorithm_b_to_a_one_pivot.c push_swap_1.c push_swap_2.c push_swap_3.c algorithm_under_4_A.c algorithm_under_4_B.c check_valid_input.c stack_link_list_peek.c stack_link_list_pushpop.c stack_print.c get_pivot.c
C_FLAG = -Wall -Wextra -Werror
LIBFT = -Llibft -lft
$(NAME): $(LIBFT)
	${CC} ${C_FLAG} $(SRCS) -o ${NAME} ${LIBFT}
$(LIBFT):
	@$(MAKE) -C ./libft all

all: $(LIBFT) $(NAME)
clean:
		@$(MAKE) -C ./libft clean
		rm -f ${OBJS}
fclean: clean
		@$(MAKE) -C ./libft clean
		rm -f ${NAME}

re: fclean all
.PHONY: all clean fclean re
