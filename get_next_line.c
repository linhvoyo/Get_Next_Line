/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:50:47 by linh              #+#    #+#             */
/*   Updated: 2018/01/01 10:40:15 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define IS_VALID(x) if (!x) return (-1);
#include <stdio.h>

static char *locate_newline(char *str)
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

static int	cal_newline(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}


int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int ret;
	static char *fd_s[1000];

	int j = 0;

	if (fd < 0)
		return (-1);
	if (!fd_s[fd])
		fd_s[fd] = "\0";
//	printf("%d\n", cal_newline(fd_s[fd]));
//	printf("%d\n", ft_strlen(fd_s[fd]));
	while (cal_newline(fd_s[fd]) == 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';	
		while (buf[ret])
		{
			if (buf[j] == '\n')
			{	
				fd_s[fd] = ft_strjoin(fd_s[fd], buf);
				*line = locate_newline(fd_s[fd]);
	//			free(fd_s[fd]);
				fd_s[fd] = (ft_strchr(fd_s[fd], '\n') + 1);
				return (1);
			}
			j++;
		}
	   	fd_s[fd] = ft_strjoin(fd_s[fd], buf);
	//	free(fd_s[fd]);
		j = 0;
	}
	if (cal_newline(fd_s[fd]) > 0)
	{
		*line = locate_newline(fd_s[fd]);
		fd_s[fd] = (ft_strchr(fd_s[fd], '\n') + 1);
		return (1);
	}
//	printf("%d\n", ft_strlen(fd_s[fd]));
	if (ft_strlen(fd_s[fd]) > 0)
	{
		*line = locate_newline(fd_s[fd]);
		fd_s[fd] = "\0";
		return (1);
	}
	return (0);
}
