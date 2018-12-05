/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:43:18 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 00:49:18 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_file_is_valid(t_asm *f, int fd)
{
	int i;
	int n;
	char *line;
	char *tmp;

	i = 0;
	n = 0;
	tmp = ft_strnew(1);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoinfree(tmp, line);
		tmp = ft_strjoinfree(tmp, "\n");
		ft_strdel(&line);
	}
	ft_get_length(f, ft_strstr(tmp, NAME_CMD_STRING), ft_strstr(tmp, COMMENT_CMD_STRING));
	f->tab = ft_strsplit(tmp, '\n');
	ft_strdel(&tmp);
	while (1)
	{
		if ((f->name == 1 && ft_strstr(f->tab[n], NAME_CMD_STRING))
		|| (f->name == 0 && ft_strstr(f->tab[n], COMMENT_CMD_STRING)))
			break ;
		else
			n++;
	}
	f->x = ft_strstr(f->tab[n], NAME_CMD_STRING)
		|| ft_strstr(f->tab[n], COMMENT_CMD_STRING) ? n + 1 : n;
}

void malloc_size(t_asm *f)
{
	f->content[NAME] = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH);
	ft_bzero(f->content[NAME], PROG_NAME_LENGTH);
	f->content[COMMENT] = (char*)malloc(sizeof(char) * COMMENT_LENGTH);
	ft_bzero(f->content[COMMENT], COMMENT_LENGTH);
	f->content[OPE] = (char*)malloc(sizeof(char) * CHAMP_MAX_SIZE);
	ft_bzero(f->content[OPE], CHAMP_MAX_SIZE);
}

int ft_check_file(t_asm *f, char *str)
{
	int i;

	i = ft_strlen(str);
	if (i > 3)
	{
		if (str[i - 1] == 's' && str[i - 2] == '.' && str[i - 3] != '/')
		{
			f->filename = ft_strdup(str);
			f->filename[i - 2] = '\0';
			f->filename = ft_strjoinfree(f->filename, ".cor");
			return (open(str, O_RDONLY, O_NOFOLLOW));
		}
	}
	return (-1);
}
