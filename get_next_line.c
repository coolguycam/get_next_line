/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:38:26 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/04 14:45:55 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_parse(char **data, char **line)
{
	char	*temp;
	int		nl;

	nl = 0;
	temp = ft_strdup(*data);
	ft_strdel(data);
	while (temp[nl] != '\n' && temp[nl] != '\0')
		nl++;
	if (temp[nl] == '\n')
	{
		temp[nl] = '\0';
		*line = ft_strdup(temp);
		*data = ft_strdup(&temp[nl + 1]);
		free(temp);
	}
	else
	{
		*line = ft_strdup(temp);
		free(temp);
	}
	return (1);
}

int		reader(const int fd, char *buff)
{
	int count;

	count = read(fd, buff, BUFF_SIZE);
	if (count > 0)
		return (count);
	else if (count == 0)
		return (0);
	else
		return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*data[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			count;

	if (line && fd >= 0 && BUFF_SIZE > 0 && read(fd, buff, 0) > -1)
	{
		if (data[fd] == NULL)
			data[fd] = (char*)ft_memalloc(1);
		while (!ft_strchr(data[fd], '\n'))
		{
			count = reader(fd, buff);
			if (count == 0)
				break ;
			buff[count] = '\0';
			temp = ft_strjoin(data[fd], buff);
			free(data[fd]);
			data[fd] = ft_strdup(temp);
			free(temp);
		}
		if (count == 0 && data[fd][0] == '\0')
			return (0);
		return (get_next_parse(&data[fd], line));
	}
	return (-1);
}
