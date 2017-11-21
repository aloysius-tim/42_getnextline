/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:53:15 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/21 22:20:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int		main(void)
{
	char *final;
	char *filename;
	int fd;

	FILE *f = fopen("final.txt", "w");

	filename = "test1.txt";
	fd = open(filename, O_RDONLY);

	while (get_next_line(fd, &final))
	{
		fprintf(f, "%s\n", final);
		//printf("\n%smain -> \"%s\"\n", KRED,final);
		//printf("%s", KNRM);
	}
//	while (1);
	/*get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED,final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED,final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED,final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED,final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);

	printf("\n****************************\n");

	get_next_line(fd, &final);
	printf("\n%smain -> \"%s\"\n", KRED, final);
	printf("%s", KNRM);*/

}
