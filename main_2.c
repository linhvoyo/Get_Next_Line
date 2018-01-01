/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 22:10:35 by linh              #+#    #+#             */
/*   Updated: 2017/12/31 22:13:30 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int fd_2;
	char *line;

	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);

	fd_2 = open("test2", O_RDONLY);
	while (get_next_line(fd_2, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd_2);
	return (0);
}
