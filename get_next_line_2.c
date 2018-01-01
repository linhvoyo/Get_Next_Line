/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:50:47 by linh              #+#    #+#             */
/*   Updated: 2017/12/31 21:55:32 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *locate_newline(char *str)
{
	int i;
	char *new;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		i++;
	}	
	new = (char*)malloc(sizeof(char) * (i + 1));
	new[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		new[i] = str[i];
		i--;
	}
	return (new);
}

int	cal_newline(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}


int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int ret;
	static char *fd_s[1000];
	char *tmp;

	int j = 0;

	if (!fd_s[fd])
		fd_s[fd] = "\0";

	while (cal_newline(fd_s[fd]) == 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';	
		while (buf[ret])
		{
			if (buf[j] == '\n')
			{	
				tmp = fd_s[fd];
				fd_s[fd] = ft_strjoin(tmp, buf);
				*line = locate_newline(fd_s[fd]);
				fd_s[fd] = (ft_strchr(fd_s[fd], '\n') + 1);
				return (1);
			}
			j++;
		}
		tmp = fd_s[fd];
	   	fd_s[fd] = ft_strjoin(tmp, buf);
		j = 0;

	}
	if (cal_newline(fd_s[fd]) > 0)
	{
		*line = locate_newline(fd_s[fd]);
		fd_s[fd] = (ft_strchr(fd_s[fd], '\n') + 1);
		return (1);
	}
	return (0);
}

#include <fcntl.h>

int main()
{
	int fd;
//	int fd_2;
	char *line;

	fd = open("test_2", O_RDONLY);
//	printf("%d\n", fd);
	int i = 0;
	while (i < 7)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		i++;
	}
//	get_next_line(fd, &line);
//  printf("%s\n", line);
//	free(line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	free(line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);

//	printf("\n");
//	fd_2 = open("test2", O_RDONLY);
//	printf("%d\n", fd_2);
//	get_next_line(fd_2, &line);
//	printf("\n");
//	get_next_line(fd_2, &line);
//	printf("\n");
//	get_next_line(fd, &line);
//	printf("\n");


//	write(1, "\n", 1);
	close(fd);
	return (0);
}
