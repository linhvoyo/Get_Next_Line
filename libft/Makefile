# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 09:30:55 by lilam             #+#    #+#              #
#    Updated: 2017/12/05 18:20:54 by lilam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

$(NAME):
	@gcc -c -Wall -Werror -Wextra -Iincludes ft_*.c 
	@ar rc libft.a ft_*.o ./includes/libft.h
	@ranlib libft.a

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean 
	@rm -rf $(NAME)

re: fclean all
