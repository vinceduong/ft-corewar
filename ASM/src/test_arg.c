/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:34:43 by tescriva          #+#    #+#             */
/*   Updated: 2018/12/06 18:29:45 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			test_arg_label(char *str, t_asm *f)
{
	int i;

	i = -1;
	if (ft_strlen(str) < 2 || str[0] != LABEL_CHAR)
		return (-1);
	if (!f->test)
		return (1);
	while (++i < f->label && ft_strcmp(str + 1, f->l[i].name))
		;
	if (i != f->label)
		return (i);
	return (-1);
}

int		get_weigth(t_asm *f)
{
	int val;
	int i;

	val = 1;
	val += op_tab[f->ope.id].ocp;
	i = -1;
	while (++i < f->ope.nb_param)
	{
		f->ope.t_arg[i] == T_DIR ? val += 4 - op_tab[f->ope.id].d2 * 2 : 0;
		f->ope.t_arg[i] == T_IND ? val += 2 : 0;
		f->ope.t_arg[i] == T_REG ? val += 1 : 0;
	}
	return (val);
}

int			ft_test_dir(char *str, t_asm *f, int nb, int res)
{
	int i;
	int lab;
	int val;
	int n;

	i = -1;
	val = 0;
	if (ft_strlen(str) < 2 || str[0] != DIRECT_CHAR)
	 	return (0);
	lab = test_arg_label(++str, f);
	lab != -1 && f->test ? f->ope.value[nb] = f->l[lab].num - f->num : 0;
	n = lab == -1 && str[0] == '-' ? 1 : 0;
	while (lab == -1 && str[++i])
	{
		(i || !n) && (str[i] > '9' || str[i] < '0') ? res = 0 : (val *= 10);
		i && n ? val -= str[i] - 48 : 0;
		!n ? val += str[i] - 48 : 0;
	}
	res && lab == -1 ? f->ope.value[nb] = val : 0;
	return (res);
}

int			ft_test_ind(char *str, t_asm *f, int nb, int res)
{
	int i;
	int lab;
	int val;
	int n;

	i = -1;
	val = 0;
	lab = test_arg_label(str, f);
	lab != -1 && f->test ? f->ope.value[nb] = f->l[lab].num - f->num : 0;
	n = lab == -1 && str[0] == '-' ? 1 : 0;
	while (lab == -1 && str[++i])
	{
		(i || !n) && (str[i] > '9' || str[i] < '0') ? res = 0 : (val *= 10);
		i && n ? val -= str[i] - 48 : 0;
		!n ? val += str[i] - 48 : 0;
	}
	res && lab == -1 ? f->ope.value[nb] = val : 0;
	return (res);
}

int		ft_test_reg(char *str, t_asm *f, int nb, int res)
{
	int i;
	int val;
	int j;

	i = 0;
	val = 0;
	j = ft_strlen(str);
	res = (j == 2 || j == 3) && str[0] == 'r' ? T_REG : 0;
	while (res && str[++i])
	{
		str[i] > '9' || str[i] < '0' ? res = 0 : 0;
		val = val * 10 + str[i] - 48;
	}
	res ? f->ope.value[nb] = val : 0;
	return (res);
}

void	ft_test_arg(t_asm *f)
{
	int i;
	int arg;

	i = -1;
	arg = 0;
	while (++i != f->ope.nb_param)
	{
		arg = 0;
		arg += ft_test_reg(f->ope.p[i], f, i, T_REG);
		arg += ft_test_dir(f->ope.p[i], f, i, T_DIR);
		arg += ft_test_ind(f->ope.p[i], f, i, T_IND);
		!(arg & op_tab[f->ope.id].arg[i]) ? error("wrong param for instruction") : 0;
		f->ope.t_arg[i] = arg;
	}
	f->num += get_weigth(f);
}
