/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:56:22 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/22 18:40:07 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	t_list	*current_elem;
	int ret = 0;

	if (!line)
		return (-1);
	if (!find_fd_list(fd))
		current_elem = ft_list_push_back(&fds, 0);
	else
		current_elem = find_fd_list(fd);
	//printf("Current FD = %d ++ Asked = %d\n", (int)current_elem->content_size, fd);
	current_elem->content_size = fd;
	//ft_strclr(*line);
	//printf("Remaining - %s -\n", current_elem->data);
	//printf("\nremaining -> \"%s\"\n", current_elem->data);
	if (!current_elem->data || ft_strlen((char *)current_elem->data) == 0)
	{
		//printf("\n------------------> Phase 1 - First round or empty buffer\n");
		ret = read_buffer(fd, line);
	//	printf("------------------------------> %s <--------\n", *line);
		if (ret == -1)
			return (-1);
		if (!(*line) || ret == 0)
			return (0);
		else if (ret == -2)
			return (1);
	}

	else if (!ft_strchr(current_elem->data, '\n') || !ft_strchr(current_elem->data, 0))
	{
		//printf("\n------------------> Phase 2 - no separator in buffer\n");
		ret = read_buffer(fd, line);
		(*line) = ft_strjoin(current_elem->data, *line);
		if (!ft_strchr(*line, '\n'))
			free(current_elem->data);
	}
	else //separator in buffer
		(*line) = ft_strdup(current_elem->data);
	//printf("\nremaining -> \"%s\"\n", current_elem->data);
	//printf("---> %s", *line);
	if ((ft_strchr(*line, '\n')))
	{
		free(current_elem->data);
		current_elem->data = ft_strdup(ft_strchr(*line, '\n') + 1);
		*(ft_strchr(*line, '\n')) = '\0';
	}
	//printf ("ret = %d\n", ret);
	//printf("- %s -", current_elem->data);
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
		exit(-1);
	//if (**final != 0)
	//	free(*final);
	//ft_strclr(*final);
	//printf(">Buffer<\n");
	*final = "";
	while ((!ft_strchr(*final, '\n') || !ft_strchr(*final, 0)))
	{
		ft_strclr(buffer);
		if ((ret_read = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		//printf("%s, %d\n", buffer, ret_read);
		tmp = ft_strdup(*final);
		if (**final != 0)
			free(*final);
		if (!(*final = (char *)malloc(sizeof(char) * (BUFF_SIZE + ft_strlen(tmp) + 1))))
			exit(-1);
		ft_strcpy(*final, tmp);
		//printf("tmp = %s\n buffer = %s\n", tmp, buffer);
		ft_strcat(*final, buffer);
		free(tmp);
		//printf("\nFinal read_buffer -> \"%s\"\n", *final);
		//printf("----> %s <-----\n", *final);
		//printf("Final final = %s\n", *final);
		if (ret_read == 0 && (*final)[ft_strlen(*final)] == 0 && ft_strlen(*final) > 0)
		{
			//printf("RetRead = %d - '%c' - %d\n", ret_read, (*final)[ft_strlen(*final)], (int)ft_strlen(*final));
			//exit(1);
			return (-2);
		}
		if (ret_read == 0)
			return (0);
		/*else if (ret_read == 0 && (*final)[ft_strlen(*final)] != '\n')
		{
			printf("OK");
			return (-2);
		}*/
	}
	//if (ret_read == 0)
	//	return (0);
	//printf("\nFinal read_buffer -> \"%s\"\n", *final);
	free(buffer);
	return (1);
}
