/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 23:32:00 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/04 13:18:53 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>

# define BUFF_SIZE 42
# define MAX_FD 4096

int		reader(int fd, char *buff);
int		get_next_parse(char **data, char **line);
int		get_next_line(const int file_d, char **line);

#endif
