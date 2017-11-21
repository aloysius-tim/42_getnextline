# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 19:41:30 by tkeynes           #+#    #+#              #
#    Updated: 2017/11/21 16:18:46 by tkeynes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

all:
	make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c -g
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c -g
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft -g

libft:
	make -C libft/ fclean && make -C libft/

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f test_gnl

re: fclean all

.PHONY: clean fclean re
