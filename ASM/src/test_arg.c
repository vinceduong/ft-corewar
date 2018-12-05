/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:34:43 by tescriva          #+#    #+#             */
/*   Updated: 2018/12/05 01:57:57 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_test_dir(char *str, t_asm *f, int nb)
{
	int i;
	int res;
	int lab;
	int val;
	int n;

	i = -1;
	n = 0;
	val = 0;
	res = T_IND;
	if (ft_strlen(str) < 2 || str[0] != DIRECT_CHAR)
	 	return (0);
	lab = test_arg_label(str + 1, f);
	lab != -1 && f->test ? f->ope.value[nb] = f->l[lab].num - f->num : 0;
	lab == -1 && str[0] == '-' ? n = 1 : 0;
	while (res && lab == -1 && str[++i])
	{
		(i || !n) && (str[i] > '9' || str[i] < '0') ? res = 0 : (val *= 10);
		i && n ? val -= str[i] - 48 : 0;
		!n ? val += str[i] - 48 : 0;
	}
	res && lab == -1 ? f->ope.value[nb] : 0;
	return (res);
}

int ft_test_ind(char *str, t_asm *f, int nb)
{
	int i;
	int res;
	int lab;
	int val;
	int n;

	i = -1;
	n = 0;
	val = 0;
	res = T_IND;
	lab = test_arg_label(str, f);
	lab != -1 && f->test ? f->ope.value[nb] = f->l[lab].num - f->num : 0;
	lab == -1 && str[0] == '-' ? n = 1 : 0;
	while (res && lab == -1 && str[++i])
	{
		(i || !n) && (str[i] > '9' || str[i] < '0') ? res = 0 : (val *= 10);
		i && n ? val -= str[i] - 48 : 0;
		!n ? val += str[i] - 48 : 0;
	}
	res && lab == -1 ? f->ope.value[nb] : 0;
	return (res);
}

int ft_test_reg(char *str, t_asm *f, int nb)
{
	int i;
	int val;
	int res;

	i = 0;
	val = 0;
	res = (ft_strlen(str) < 2 || ft_strlen(str) > 3 || arg[0] != 'r') ? res = 0 : T_REG;
	while (res && arg[i])
	{
		arg[i] > '9' || arg[i] < '0' ? res = 0 : 0;
		r = r * 10 + arg[i] - 48;
		i++;
	}
	res ? f->ope.value[nb] = r : 0;
	return (res);
}

void ft_test_arg(t_asm *f)
{
	int i;
	int arg;

	i = -1;
	while (++i < f->ope.nb_param)
	{
		arg = 0;
		ft_check_arg(f, f->ope.p[i], , i);
		arg += ft_test_reg(f->ope.p[i], f, i);
		arg += ft_test_dir(f->ope.p[i], f, i);
		arg += ft_test_ind(f->ope.p[i], f, i);
		!(arg & op_tab[f->ope.id].arg[1]) ? error("wrong param for instruction") : 0;
		f->ope.t_arg[i] = arg;
	}
}
