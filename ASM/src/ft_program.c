/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:50:38 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 01:33:56 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_add_label_name(t_asm *f, int n, int i)
{
	int i2;
	int j;
	int nl;

	i2 = i;
	nl = f->label - 1;
	while (i2-- >= 0 && ft_labchar(f->tab[n][i2]))
		j++;
	f->l[nl].name = ft_strsub(f->tab[n] + i2, 0, j);
	f->l[nl].num = f->label;
	f->l[nl].n = n;
	f->l[nl].i = i;

}

void ft_add_label(t_asm *f, int n, int i)
{
	f->label++;
	f->l = f->l ? realloc(f->l, sizeof(t_lab) * f->label)
		: malloc(sizeof(t_lab) * 1);
	!f->l ? error("malloc Failed") : ft_add_label_name(f, n, i);
}

void ft_get_operation(t_asm *f)
{
	int n;
	int i;
	char c;

	n = f->x;
	i = 0;
	while (f->tab[n])
	{
		while (f->tab[n][i] && (f->tab[n][i] == ' ' || f->tab[n][i] == '\t'))
			i++;
		while (f->tab[n][i] && !ft_labchar(f->tab[n][i]))
			i++;
		if (i >= 1 && f->tab[n][i] == LABEL_CHAR && ft_labchar(f->tab[n][i - 1]))
			ft_add_label(f, n, i);
		else
			i = 0;
		ft_ope_arg(f->tab[n] += i + 1, f);
		n++;
	}
	printf("gg\n" );
	//f->num = 0;
	i = 0;
	n = f->x - 1;
	while (f->tab[++n])
		ft_ope_arg(f->tab[n], f);
}

void ft_program(t_asm *f)
{
	t_header e;

	ft_get_operation(f);
	f->fd = open(f->filename, O_CREAT | O_WRONLY | O_TRUNC
		| S_IRUSR | S_IWUSR);
	if (f->fd == -1)
		error("can't create file");
	ft_bzero(&e, sizeof(e));
	e.magic = swap_uint(COREWAR_EXEC_MAGIC);
	ft_strcpy(e.prog_name, f->content[NAME]);
	ft_strcpy(e.comment, f->content[COMMENT]);
	e.prog_size = swap_uint(f->ope_size);
	write(f->fd, &e, sizeof(e));
}
