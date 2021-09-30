#! /bin/bash

gcc -g3 -fsanitize=address *.c
# gcc *.c
./a.out