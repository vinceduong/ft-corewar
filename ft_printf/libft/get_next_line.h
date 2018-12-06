/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:24:41 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:54:02 by vduong           ###   ########.fr       */
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
