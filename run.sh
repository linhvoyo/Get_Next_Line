#!/bin/bash

make -C libft/ fclean && make -C libft/
gcc -g -Wall -Wextra -Werror -I./libft/includes/ -L./libft -lft -o gnl get_next_line.c main.c
##clang -g -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
##clang -g -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
##clang -g -o test_gnl get_next_line.o -I libft/includes -L libft/ -lft


