/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:56:22 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/21 22:27:28 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char ** line)
{
	t_list	*current_elem;

	if (!ft_list_size(fds) || !find_fd_list(fd))
		current_elem = ft_list_push_back(&fds, 0);
	else
		current_elem = find_fd_list(fd);
	current_elem->content_size = fd;

	//printf("\nremaining -> \"%s\"\n", current_elem->data);
	if (!current_elem->data || ft_strlen((char *)current_elem->data) == 0)
	{
		//printf("\n------------------> Phase 1 - First round or empty buffer\n");
		(*line) = read_buffer(fd);
		if (!(*line))
		{
			free(*line);
			*line = ft_strnew(1);
			**line = 0;
			return (0);
		}
		//free(current_elem->data);
	}

	else if (!ft_strchr(current_elem->data, '\n') || !ft_strchr(current_elem->data, 0))
	{
		//printf("\n------------------> Phase 2 - no separator in buffer\n");
		(*line) = ft_strjoin(current_elem->data, read_buffer(fd));
		if (!ft_strchr(*line, '\n'))
			current_elem->data = 0;
		//free(current_elem->data);
	}
	else //separator in buffer
		(*line) = ft_strdup(current_elem->data);
	//printf("\nremaining -> \"%s\"\n", current_elem->data);
	
	if ((ft_strchr(*line, '\n')))
	{
		free(current_elem->data);
		current_elem->data = ft_strdup(ft_strchr(*line, '\n') + 1);
		*(ft_strchr(*line, '\n')) = '\0';
	}

	/*while (current_elem->next)
	{
		current_elem = current_elem->next;
		free(fds->data);
		free(fds);
	}*/
	return (1);
}

t_list		*find_fd_list(int const fd)
{
	t_list	*tmp;

	tmp = fds;
	if (!fds)
		return (0);
	if ((const int)tmp->content_size == fd)
		return (tmp);
	while (tmp->next)
	{
		if ((const int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

char	*read_buffer(int const fd)
{
	int		ret_read;
	char	*buffer;
	char	*tmp;
	char	*final;

	if ((buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE))) == 0)
		return (0);
	final = "";
	while (!ft_strchr(final, '\n') || !ft_strchr(final, 0))
	{
		ret_read = read(fd, buffer, BUFF_SIZE);
		if (ret_read < 0)
			exit(-1);
		buffer[ret_read] = 0;
		if (ret_read == 0)
			return (0);
		tmp = ft_strdup(final);
		if (!(final = (char *)malloc(sizeof(char) * (BUFF_SIZE + ft_strlen(tmp) + 1))))
			return (0);
		ft_strcpy(final, tmp);
		ft_strcat(final, buffer);
		free(tmp);
	}
	//printf("\nFinal read_buffer -> \"%s\"\n", final);
	free(buffer);
	return (final);
}
