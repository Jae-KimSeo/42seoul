#!/bin/sh

gcc minishell.c -o simple_code -lreadline -L/Users/jae-kim/.brew/opt/readline/lib -I/Users/jae-kim/.brew/opt/readline/include -fsanitize=address
./simple_code env
