/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:43:18 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/07 17:13:36 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_supp_comment(char *str)
{
	int i;
	int n;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i >= 1 && str[i - 1] != '\n')
		{
			n = i - 1;
			while (n >= 0 && str[n] != '\n' &&
				(str[n] == ' ' || str[n] == '\t'))
				str[n--] = '\n';
		}
		if (str[i] == COMMENT_CHAR)
		{
			n = i - 1;
			while (str[i] != '\n')
				str[i++] = '\n';
			while (n >= 0 && str[n] != '\n' &&
				(str[n] == ' ' || str[n] == '\t'))
				str[n--] = '\n';
		}
		i++;
	}
	return (str);
}

char	*ft_read_data_for_real(int fd)
{
	char	*tmp;
	char	*line;
	int		ret;

	tmp = ft_strnew(1);
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strjoinfree(tmp, line);
		tmp = ft_strjoinfree(tmp, "\n");
		ft_strdel(&line);
	}
	return (tmp);
}

void	ft_file_is_valid(t_asm *f, int fd)
{
	int		i;
	int		n;
	char	*line;
	char	*tmp;

	i = 0;
	n = 0;
	tmp = ft_read_data_for_real(fd);
	ft_get_length(f, ft_strstr(tmp, NAME_CMD_STRING),
		ft_strstr(tmp, COMMENT_CMD_STRING));
	f->tab = ft_strsplit(ft_supp_comment(tmp), '\n');
	ft_strdel(&tmp);
	while (1)
	{
		if ((f->name == 1 && ft_strstr(f->tab[n], NAME_CMD_STRING))
		|| (f->name == 0 && ft_strstr(f->tab[n], COMMENT_CMD_STRING)))
		{
			f->x = n + 1;
			break ;
		}
		else
			n++;
	}
}

void	malloc_size(t_asm *f)
{
	f->content[NAME] = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH);
	ft_bzero(f->content[NAME], PROG_NAME_LENGTH);
	f->content[COMMENT] = (char*)malloc(sizeof(char) * COMMENT_LENGTH);
	ft_bzero(f->content[COMMENT], COMMENT_LENGTH);
}

int		ft_check_file(t_asm *f, char *str)
{
	int		i;
	int		fd;
	char	err[1];

	i = ft_strlen(str);
	if (i > 3)
	{
		if (str[i - 1] == 's' && str[i - 2] == '.' && str[i - 3] != '/')
		{
			f->filename = ft_strdup(str);
			f->filename[i - 2] = '\0';
			f->filename = ft_strjoinfree(f->filename, ".cor");
			fd = open(str, O_RDONLY | O_NOFOLLOW);
			fd == -1 ? error("can't open file") : 0;
			lseek(fd, 0, SEEK_END);
			read(fd, err, 1) > 0 ? error("can't open file") : 0;
			lseek(fd, 0, SEEK_SET);
			return (fd);
		}
	}
	return (-1);
}
