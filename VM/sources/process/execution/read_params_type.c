/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:24:20 by vduong            #+#    #+#             */
/*   Updated: 2018/11/30 19:30:08 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_params_type(t_operation *ope, unsigned char ocp)
{
	t_arg_type		*type;
	t_op			op;
	int				i;
	int				v;

	i = -1;
	type = ope->param_type;
	op = op_tab[ope->opcode - 1];
	type[0] = ocp >> 6;
	type[1] = op.nb_param >= 2 ? (ocp >> 4) & 3 : 0;
	type[2] = op.nb_param >= 3 ? (ocp >> 2) & 3 : 0;
	while (++i < op.nb_param)
	{
		v = 0;
		if (ope->param_type[i] == REG_CODE)
			v = T_REG;
		if (ope->param_type[i] == IND_CODE)
			v = T_IND;
		if (ope->param_type[i] == DIR_CODE)
			v = T_DIR;
		!(v & op.arg[i]) ? ope->error = 1 : 0;
	}
}
