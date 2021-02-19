# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toispre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 17:01:08 by toispre           #+#    #+#              #
#    Updated: 2021/02/03 19:10:11 by toispre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
NAME = cub3D
SRCS = main.c draw_minimap.c draw_minimap_2.c key.c key_update.c screen_casting.c load.c ./gnl/get_next_line.c get_map.c sprite_casting.c sprite_casting_2.c bmp_save.c cub_init.c error_check.c error_check_2.c set_map.c cub3d_utils.c floor_casting.c wall_casting.c wall_casting_2.c 
C_FLAG = -framework OpenGL -framework AppKit
B_FLAG = -D BUFFER_SIZE=10
LIBFT = -L./libft -lft
MLX = -L./mlx -lmlx

$(NAME): $(LIBFT)
	 ${CC} ${LIBFT} ${MLX} ${C_FLAG} ${B_FLAG} ${SRCS} -o $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./libft all


all: 	$(LIBFT) $(NAME)
 	
	
clean:
	@$(MAKE) -C ./libft clean
	rm -f ${OBJS}

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
