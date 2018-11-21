/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:29:35 by tescriva          #+#    #+#             */
/*   Updated: 2018/11/05 12:07:39 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_read_data(int fd)
{
	char *line;
	char *str;

	str = ft_memalloc(1);
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n\0");
		ft_strdel(&line);
	}
	return (str);
}
