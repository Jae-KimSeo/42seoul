#!/bin/bash
rm ./test_json
gcc -Wall -Wextra -Werror -o test_json *.c -L ./lib/libft -lft -fsanitize=address
./test_json
