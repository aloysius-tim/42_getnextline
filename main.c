/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:53:15 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/22 19:35:24 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*final;
	char	*filename;
	int		fd;
	int		ret;
	FILE	*f;

	f = fopen("final.txt", "w");
	filename = "test5.txt";
	fd = open(filename, O_RDONLY);
	while ((ret = get_next_line(fd, &final)))
	{
		printf("%s = %d\n\n\n", final, ret);
	}
	printf("--> Ret = %d\n", ret);
}
