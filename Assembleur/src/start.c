/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:29:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/07 14:03:41 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_info(t_asm *f)
{
	ft_putstr(RED_BOLD);
	ft_putstr("\nNAME :	");
	ft_putstr(NONE);
	ft_putendl(f->content[NAME]);
	ft_putstr(YELLOW);
	ft_putstr("COMMENT : ");
	ft_putstr(NONE);
	ft_putendl(f->content[COMMENT]);
	ft_putstr(MAGENTA);
	ft_putstr("SIZE (CHAMP) : ");
	ft_putstr(NONE);
	ft_putnbr(f->num);
	ft_putendl(" Bytes");
	ft_putstr(CYAN);
	ft_putstr("SIZE (FILE) : ");
	ft_putstr(NONE);
	ft_putnbr(f->num + sizeof(t_header));
	ft_putendl(" Bytes");
	ft_putstr(GREEN);
	ft_putstr("NB INSTRUCTION : ");
	ft_putstr(NONE);
	ft_putnbr(f->instruction);
	ft_putchar('\n');
}

void	free_the_whole_world(t_asm *f)
{
	int i;
	int n;

	i = -1;
	while (f->label && ++i < f->label)
		ft_strdel(&f->l[i].name);
	i = 0;
	while (f->tab[i])
	{
		ft_strdel(&f->tab[i]);
		i++;
	}
	ft_strdel(&f->filename);
	ft_strdel(&f->content[NAME]);
	ft_strdel(&f->content[COMMENT]);
	free(f->tab);
	free(f->content);
	f->l ? free(f->l) : 0;
	f->l = NULL;
	f = NULL;
}

void	ft_start(t_asm *f, char **av, int ac)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		fd = ft_check_file(f, av[i]);
		if (fd != -1)
		{
			f->content = (char **)malloc(sizeof(char*) * 1);
			malloc_size(f);
			ft_file_is_valid(f, fd);
			close(fd);
			ft_program(f);
			ft_print_info(f);
			free_the_whole_world(f);
		}
		else
		{
			tmp = ft_strjoin("the file ", av[i]);
			error(ft_strjoinfree(tmp, " is not a valid file"));
		}
		i++;
	}
}
