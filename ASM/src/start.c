/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:29:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/06 19:22:40 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_the_whole_world(t_asm *f)
{
	int i;

	i = -1;
	while (++i < f->label)
		ft_strdel(&f->l[i].name);
	i = -1;
	while (f->tab[++i])
		free(f->tab[i]);
	ft_strdel(&f->content[NAME]);
	ft_strdel(&f->content[COMMENT]);
	ft_strdel(&f->filename);
	free(f->tab);
	free(f->l);
	free(f->content);
	free(f->part);
}

void	ft_start(t_asm *f, char **av, int ac)
{
	int fd;
	int i;
	char *tmp;

	i = 1;
	while (i < ac)
	{
		fd = ft_check_file(f, av[i]);
		if (fd != -1)
		{
			f->content = (char **)malloc(sizeof(char*) * 2);
			malloc_size(f);
			ft_file_is_valid(f, fd);
			close(fd);
			ft_program(f);
			free_the_whole_world(f);
		}
		else
		{
			tmp = ft_strjoin("the file ", f->filename);
			error(ft_strjoinfree(tmp, " is not a valid file"));
		}
		i++;
	}
}
