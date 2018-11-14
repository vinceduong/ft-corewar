/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:24:41 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 20:45:03 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "get_next_line.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct			s_gnl
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
