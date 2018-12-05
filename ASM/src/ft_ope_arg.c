/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:48:00 by tescriva          #+#    #+#             */
/*   Updated: 2018/12/05 19:00:12 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void free_ope(t_asm *f)
{
	int i;

	i = -1;
	while (++i < f->ope.nb_param && !(f->ope.param[i] = 0))
		ft_strdel(&(f->ope.p[i]));
	ft_strdel(&(f->ope.name));
	f->ope.nb_param = 0;
	f->ope.id = 0;
}

void ft_nb_param(t_asm *f)
{
	f->ope.id = -1;
	printf("next instru = (%s)\n", f->ope.name);
	while (++f->ope.id < 16 && ft_strcmp(op_tab[f->ope.id].name, f->ope.name))
		;
	f->ope.id == 16 ? error("Instruction is wrong") : 0;
	f->ope.nb_param = op_tab[f->ope.id].nb_param;
}

void ft_check_param(char *str, t_asm *f)
{
	int i;
	int nb;
	int n;

	i = 0;
	nb = -1;
	printf("\n------- NEW PARAM -------\n");
	printf("	%s\n", f->ope.name);
	printf("----------------------------\n");
	printf("	%s\n***************************\n", str);
	while (++nb < f->ope.nb_param)
	{
		n = 0;
		while (str[i + n] && str[i + n] != ' ' && str[i + n] != '\t'
				&& str[i + n] != SEPARATOR_CHAR)
			n++;
		f->ope.param[nb] = n;
		f->ope.p[nb] = ft_strsub(str, i, f->ope.param[nb]);
		printf("parametre = {%s}\n", f->ope.p[nb]);
		while (str[++i] && str[i] != ' ' && str[i] != '\t' && str[i] != SEPARATOR_CHAR)
			;
		--i;
		while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
			;
		if (str[i] == COMMENT_CHAR)
			break ;
		(str[i] && nb == f->ope.nb_param - 1) || (str[i] != SEPARATOR_CHAR && str[i])
			|| f->ope.p[nb][0] == 0 ? error("Wrong Number of param") : 0;
		while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
			;
	}
	//nb != f->ope.nb_param ? error("Comment Char before param") : 0;
}

void ft_fill_ope(char *str, t_asm *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && str[i + j] != ' ' && str[i + j] != '\t')
		j++;
	f->ope.name = ft_strsub(str, i, j);
	i = i + j;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	ft_nb_param(f);
	ft_check_param(str + i, f);
	ft_test_arg(f);
}

void ft_ope_arg(char *str, t_asm *f)
{
	int i;
	int val;

	i = -1;
	val = 0;
	f->no_error = 0;
	ft_bzero(&f->ope, sizeof(f->ope));
	while (str[++i])
		str[i] != ' ' || str[i] != '\t' ? val++ : 0;
	val ? ft_fill_ope(str, f) : 0;
	val ? f->no_error = 1 : 0;
	val && f->test == 2 ? f->instruction++ : 0;
	free_ope(f);
}
