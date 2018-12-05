/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_cor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:03:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 19:23:18 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void put_ocp(t_asm *f)
{
	int i;
	char ocp;
	char tmp;

	i = 0;
	ocp = 0;
	while (i < f->ope.nb_param)
	{
		tmp = 0;
		f->ope.t_arg[i] == T_REG ? tmp = 1 : 0;
		f->ope.t_arg[i] == T_DIR ? tmp = 2 : 0;
		f->ope.t_arg[i] == T_IND ? tmp = 3 : 0;
		ocp += tmp << (2 * (3 - i));
		i++;
	}
	write(f->fd, &ocp, 1);
}

void put_arg(t_asm *f)
{
	int i;
	int nb;
	short nb1;
	char nb2;
	i = 0;
	while (i < f->ope.nb_param)
	{
		nb1 = swap_short(f->ope.value[i]);
		nb = swap_int(f->ope.value[i]);
		f->ope.t_arg[i] == T_REG ? write(f->fd, &f->ope.value[i], 1) : 0;
		f->ope.t_arg[i] == T_DIR && op_tab[f->ope.id].d2 ? write(f->fd, &nb, 4) : 0;
		(f->ope.t_arg[i] == T_DIR && op_tab[f->ope.id].d2) || f->ope.t_arg[i] == T_IND ? write(f->fd, &nb1, 2) : 0;
		i++;
	}
}

void write_instruction(char *str, t_asm *f)
{
	write(f->fd, &op_tab[f->ope.id].id, 1);
	op_tab[f->ope.id].ocp ? put_ocp(f) : 0;
	put_arg(f);
}

void ft_write_prog(t_asm *f)
{
	int n;

	n = f->x;
	f->test = 2;
	f->num = 0;
	while (f->tab[n])
	{
		ft_ope_arg(f->tab[n], f);
		f->no_error ? write_instruction(f->tab[n], f) : 0;
		n++;
	}
}