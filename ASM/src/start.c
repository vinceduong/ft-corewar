/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:29:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 19:18:09 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
			f->content = (char **)malloc(sizeof(char*) * 3);
			malloc_size(f);
			ft_file_is_valid(f, fd);
			close(fd);
			ft_program(f);
			free_the_whole_word(f);
		}
		else
			error(ft_strjoin(ft_strjoin("the file ", f->filename), " is not a valid file"));
		printf("FINISH = %s\n", f->filename);
		free(f->filename);
		i++;
	}
}
