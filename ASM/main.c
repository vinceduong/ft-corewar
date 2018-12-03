/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:06 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/03 16:54:05 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void error(char *str)
{
	ft_printf("Error : %s", str);
	exit (1);
}

void ft_file_is_valid(t_asm *f, int fd)
{
	int i;
	char *line;
	char *tmp;

	i = 0;
	tmp = ft_strnew(1);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoinfree(tmp, line);
		ft_strdel(line);
	}
	f->tab = ft_strsplit(tmp, '\n');
	ft_strdel(tmp);
	ft_get_name(f);
	ft_get_comment(f);
	ft_get_content(f);
}

void free_the_whole_word(t_asm *f)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_strdel(f->content[i]);
		i++;
	}
	free(f->content);
	free(f->part);
}

void malloc_size(t_asm *f)
{
	int i;

	i = 0;

	f->content[0] = (char*)malloc(sizeof(char) * 4);
	ft_bzero(f->content[0], 4);
	f->content[1] = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH);
	ft_bzero(f->content[0], PROG_NAME_LENGTH);
	f->content[2] = (char*)malloc(sizeof(char) * COMMENT_LENGTH);
	ft_bzero(f->content[0], COMMENT_LENGTH);
	f->content[3] = (char*)malloc(sizeof(char) * CHAMP_MAX_SIZE);
	ft_bzero(f->content[0], CHAMP_MAX_SIZE);
}

void ft_start(t_asm *f, char **av)
{
	int fd;
	int i;

	i = 1;
	while (av[i])
	{
		fd = ft_check_file(f, av);
		if (fd != -1)
		{
			f->content = (char **)malloc(sizeof(char*) * 3);
			malloc_size(f);
			f->part = (int **)
			ft_file_is_valid(f, fd);
			close(fd);
			free_the_whole_word(f);
		}
		else
			ft_printf("The File : %s is not a valide File\n", av[i]);
		ft_printf("Writing output program to %s.cor", ft_strstr(av[i], ".s"));
		i++;
	}
}

int main(int ac, char **av)
{
	t_asm f;

	if (ac >= 2)
	{
		ft_bzero(f, sizeof(t_asm));
		ft_start(&f, av);
	}
	else
		ft_printf("usage : ./asm [Exemple.s] [Exemple2.s] ...\n");
	return (0);
}
