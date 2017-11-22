# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 19:41:30 by tkeynes           #+#    #+#              #
#    Updated: 2017/11/21 16:01:30 by tkeynes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strstr.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strsplit.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		btree_apply_infix.c \
		btree_apply_prefix.c \
		btree_apply_suffix.c \
		btree_create_node.c \
		btree_insert_data.c \
		btree_search_item.c \
		btree_level_count.c \
		btree_apply_by_level.c \
		ft_create_elem.c \
		ft_list_push_back.c \
		ft_list_push_front.c \
		ft_list_size.c \
		ft_list_last.c \
		ft_list_push_params.c \
		ft_list_clear.c \
		ft_list_at.c \
		ft_list_reverse.c \
		ft_list_foreach.c \
		ft_list_foreach_if.c \
		ft_list_find.c \
		ft_list_remove_if.c \
		ft_list_merge.c \
		ft_list_sort.c \
		ft_sorted_list_insert.c \
		ft_sorted_list_merge.c

OBJ = $(SRC:.c=.o)
	HEADER = -I includes/libft.h -I

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c $(SRC) $(HEADER) -Wall -Wextra -Werror
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<


clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
