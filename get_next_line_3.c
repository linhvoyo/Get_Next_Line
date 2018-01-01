/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:50:47 by linh              #+#    #+#             */
/*   Updated: 2017/12/31 21:55:55 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define MALLCHECK(x) if (!x) return (-1);

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

	int i = 0;
	int j = 0;

	if (!fd_s[fd])
		fd_s[fd] = "\0";
//	printf("%s", fd_s[fd]);
//	printf("%d\n", ft_strcmp(fd_s[fd], "\0"));
//	while (!ft_strcmp(fd_s[fd], "\0")  && (ret = read(fd, buf, BUFF_SIZE)))
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
			//	*line = ft_strjoin(fd_s[fd], locate_newline(buf));
			//	fd_s[fd] = ft_strchr(buf, '\n');

		//		printf("%s", fd_s[fd]);


				
		//		printf("%s\n", ft_strchr(buf, '\n'));
		//		*line = ft_strjoin(fd_s[fd], buf);
		//		fd_s[fd] = ft_strjoin(tmp, buf);
				return (1);
			}
			j++;
		}
		tmp = fd_s[fd];
	   	fd_s[fd] = ft_strjoin(tmp, buf);	
//		printf("%s", ft_strchr(buf, '\n'));
		i = i + ret;
		j = 0;

	}

//	if (ft_strcmp(fd_s[fd], "\0") != 0 && cal_newline(fd_s[fd]) > 0)
	if (cal_newline(fd_s[fd]) > 0)
	{
		
//		printf("%zu\n", ft_strlen(locate_newline(fd_s[fd])));
		*line = locate_newline(fd_s[fd]);

//		 printf("%d\n", cal_newline(fd_s[fd]));
//		if (ft_strlen(locate_newline(fd_s[fd])) != ft_strlen(fd_s[fd]))
//			*line = locate_newline(fd_s[fd]);

		fd_s[fd] = (ft_strchr(fd_s[fd], '\n') + 1);
		return (1);
	}

	
//	printf("%s\n", fd_s[fd]);


//	printf("%d\n", ret);
//	printf("%d\n", i);
	return (0);
}

#include <fcntl.h>

int main()
{
	int fd;
//	int fd_2;
	char *line;

	fd = open("test", O_RDONLY);
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
