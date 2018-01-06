/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 05:26:42 by jrameau           #+#    #+#             */
/*   Updated: 2017/12/29 18:10:49 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// static void simple_string(t_test *test)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	char 	*str;
// 	int		gnl_ret;
//
// 	str = (char *)malloc(1000 * 1000);
// 	*str = '\0';
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	out = dup(1);
// 	pipe(p);
// 	dup2(p[1], 1);
//
// 	write(1, str, strlen(str));
// 	close(p[1]);
// 	dup2(out, 1);
// 	gnl_ret = get_next_line(p[0], &line);
// 	mt_assert(strcmp(line, str) == 0);
// 	mt_assert(gnl_ret == 0 || gnl_ret == 1);
// }


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = -1;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
//	printf("%s\n", line);
	while (get_next_line(fd, &line) == 1 )
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	// argc = 0;
	// argv = 0;
	//
	// char 	*line;
	// int		out;
	// int		p[2];
	// char 	*str;
	// int		gnl_ret;
	// str = (char *)malloc(1000 * 1000);
	// *str = '\0';
	// ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	// ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	// ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	// out = dup(1);
	// pipe(p);
	// dup2(p[1], 1);
	//
	// write(1, str, strlen(str));
	// close(p[1]);
	// dup2(out, 1);
	// gnl_ret = get_next_line(p[0], &line);
	//
	// // puts("hi");
	// // printf("%s", line);
	// printf("%s", str);
	return (0);
}
