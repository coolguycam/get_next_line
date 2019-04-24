/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:45:47 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/17 23:34:01 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		close(fd);
	}
	return (0);
}
