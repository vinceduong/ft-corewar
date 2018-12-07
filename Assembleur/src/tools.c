/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:26:23 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/07 14:27:19 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*re_malloc(t_asm *f, int n, int i)
{
	char	*tmp;

	tmp = ft_strdup(f->tab[n] + i + 1);
	ft_strdel(&f->tab[n]);
	f->tab[n] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (f->tab[n]);
}

int		get_weigth(t_asm *f)
{
	int val;
	int i;

	val = 1;
	val += g_op_tab[f->ope.id].ocp;
	i = -1;
	while (++i < f->ope.nb_param)
	{
		f->ope.t_arg[i] == T_DIR ? val += 4 - g_op_tab[f->ope.id].d2 * 2 : 0;
		f->ope.t_arg[i] == T_IND ? val += 2 : 0;
		f->ope.t_arg[i] == T_REG ? val += 1 : 0;
	}
	return (val);
}

int		ft_labchar(char c)
{
	int i;

	i = -1;
	while (LABEL_CHARS[++i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

void	error(char *str)
{
	ft_putstr("Error : ");
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}
