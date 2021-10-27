#!/bin/bash

gcc -Wall -Wextra -Werror *.c -L ./lib/libft -lft -fsanitize=address
./a.out
