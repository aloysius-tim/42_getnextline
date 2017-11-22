/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:56:22 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/22 19:32:04 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	t_list	*current_elem;
	int		ret;

	if (!line)
		return (-1);
	if (!find_fd_list(fd))
		current_elem = ft_list_push_back(&g_fds, 0);
	else
		current_elem = find_fd_list(fd);
	current_elem->content_size = fd;
	if ((ret = iterations(current_elem, line, fd)) == -100)
		(void)ret;
	else
		return (ret);
	if ((ft_strchr(*line, '\n')))
	{
		free(current_elem->data);
		current_elem->data = ft_strdup(ft_strchr(*line, '\n') + 1);
		*(ft_strchr(*line, '\n')) = '\0';
	}
	return (1);
}

int		iterations(t_list *current_elem, char **line, int fd)
{
	int ret;

	*line = "";
	if (!current_elem->data || ft_strlen((char *)current_elem->data) == 0)
	{
		ret = read_buffer(fd, line);
		if (ret == -1)
			return (-1);
		if (!(*line) || ret == 0)
			return (0);
		else if (ret == -2)
			return (1);
	}
	else if (!ft_strchr(current_elem->data, '\n') ||
!ft_strchr(current_elem->data, 0))
	{
		read_buffer(fd, line);
		(*line) = ft_strjoin(current_elem->data, *line);
		if (!ft_strchr(*line, '\n'))
			free(current_elem->data);
	}
	else
		(*line) = ft_strdup(current_elem->data);
	return (-100);
}

t_list	*find_fd_list(int const fd)
{
	t_list	*tmp;

	tmp = g_fds;
	if (!g_fds)
		return (0);
	if ((const int)tmp->content_size == fd)
		return (tmp);
	while (tmp)
	{
		if ((const int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int		read_buffer(int const fd, char **final)
{
	int		ret_read;
	char	*tmp;
	char	*buffer;

	if ((buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE))) == 0)
		return (-1);
	while ((!ft_strchr(*final, '\n') || !ft_strchr(*final, 0)))
	{
		ft_strclr(buffer);
		tmp = ft_strdup(*final);
		(**final != 0) ? free(*final) : (void)(*final);
		if ((!(*final = (char *)malloc((BUFF_SIZE + ft_strlen(tmp) + 1)))) ||
((ret_read = read(fd, buffer, BUFF_SIZE)) == -1))
			return (-1);
		ft_strcpy(*final, tmp);
		ft_strcat(*final, buffer);
		free(tmp);
		if (ret_read == 0 && (*final)[ft_strlen(*final)] == 0 &&
				ft_strlen(*final) > 0)
			return (-2);
		if (ret_read == 0)
			return (0);
	}
	free(buffer);
	return (1);
}
