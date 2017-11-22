/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:56:40 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/22 19:31:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFF_SIZE 4

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct	s_fd
{
	char		*data;
	struct s_fd	*next;
	int			fd_num;
}				t_fd;
static t_list	*g_fds;
int				get_next_line(int const fds, char **line);
int				read_buffer(int const fd, char **final);
t_list			*find_fd_list(int const fd);
char			*str_comb(char *str1, char *str2);
int				iterations(t_list *current_elem, char **line, int fd);

#endif
