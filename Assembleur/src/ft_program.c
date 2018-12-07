/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:50:38 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/07 14:27:15 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_add_label_name(t_asm *f, int n, int i)
{
	int l;
	int j;
	int nl;

	l = 0;
	j = 0;
	nl = f->label - 1;
	while (f->tab[n][l] && (f->tab[n][l] == ' ' || f->tab[n][l] == '\t'))
		l++;
	i -= l;
	f->l[nl].name = ft_strsub(f->tab[n] + l, 0, i);
	f->l[nl].num = f->num;
	f->l[nl].n = n;
	f->l[nl].i = i + 2;
}

void	ft_add_label(t_asm *f, int n, int i)
{
	f->label++;
	f->l = !f->l ? malloc(sizeof(t_lab) * 1)
		: realloc(f->l, sizeof(t_lab) * f->label);
	!f->l ? error("malloc Failed") : ft_add_label_name(f, n, i);
}

void	ft_get_operation(t_asm *f)
{
	int		n;
	int		i;
	char	c;

	n = f->x - 1;
	f->label = 0;
	f->l = NULL;
	f->test = 0;
	while (f->tab[++n])
	{
		i = 0;
		f->test = 0;
		while (f->tab[n][i] && (f->tab[n][i] == ' ' || f->tab[n][i] == '\t'))
			i++;
		while (f->tab[n][i] && ft_labchar(f->tab[n][i]))
			i++;
		i >= 1 && f->tab[n][i] == LABEL_CHAR && ft_labchar(f->tab[n][i - 1]) ?
			ft_add_label(f, n, i) : (i = 0);
		ft_ope_arg(re_malloc(f, n, i), f);
	}
	f->test = 1;
	f->num = 0;
	n = f->x - 1;
	while (f->tab[++n])
		ft_ope_arg(f->tab[n], f);
}

void	write_header(t_asm *f)
{
	t_header e;

	f->fd = open(f->filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (f->fd == -1)
		error("can't create file");
	ft_bzero(&e, sizeof(e));
	e.magic = swap_uint(COREWAR_EXEC_MAGIC);
	ft_strcpy(e.prog_name, f->content[NAME]);
	ft_strcpy(e.comment, f->content[COMMENT]);
	e.prog_size = swap_uint(f->num);
	write(f->fd, &e, sizeof(e));
}

void	ft_program(t_asm *f)
{
	char *tmp;

	ft_get_operation(f);
	write_header(f);
	tmp = ft_strdup("Writing output program to ");
	tmp = ft_strjoinfree(tmp, f->filename);
	ft_putendl(tmp);
	ft_strdel(&tmp);
	ft_write_prog(f);
}
