/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:06 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/03 18:53:57 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char *ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

void error(char *str)
{
	printf("Error : %s", str);
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
		tmp = ft_strjoinfree(tmp, "\n");
		ft_strdel(&line);
	}
	f->tab = ft_strsplit(tmp, '\n');
	ft_strdel(&tmp);
	ft_get_name(f);
	ft_get_comment(f);
	printf("%s\n%s\n", f->content[NAME], f->content[COMMENT]);
	//ft_get_content(f);
}

void free_the_whole_word(t_asm *f)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_strdel(&f->content[i]);
		i++;
	}
	free(f->content);
	free(f->part);
}

void malloc_size(t_asm *f)
{
	f->content[MAGIC] = (char*)malloc(sizeof(char) * 4);
	ft_bzero(f->content[MAGIC], 4);
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

void ft_start(t_asm *f, char **av, int ac)
{
	int fd;
	int i;

	i = 1;
	while (i < ac)
	{
		fd = ft_check_file(f, av[i]);
		if (fd != -1)
		{
			f->content = (char **)malloc(sizeof(char*) * 4);
			malloc_size(f);
			ft_file_is_valid(f, fd);
			close(fd);
			free_the_whole_word(f);
		}
		else
			error(ft_strjoin(ft_strjoin("the file ", f->filename), "is not a valid file\n"));
		printf("Writing output program to %s\n", f->filename);
		free(f->filename);
		i++;
	}
}

int main(int ac, char **av)
{
	t_asm f;

	if (ac >= 2)
	{
		ft_bzero(&f, sizeof(t_asm));
		ft_start(&f, av, ac);
	}
	else
		printf("usage : ./asm [Exemple.s] [Exemple2.s] ...\n");
	return (0);
}
