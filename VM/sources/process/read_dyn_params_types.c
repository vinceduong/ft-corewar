/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dyn_params_types.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:24:59 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 12:21:55 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	test_valid_param(t_instruction *inst, t_op o)
{
	int i;
	int v;

	i = -1;
	while (++i < o.nb_param)
	{
		v = 0;
		inst->param_types[i] == REG_CODE ?
			v = T_REG : 0;
		inst->param_types[i] == DIR_CODE ?
			v = T_DIR : 0;
		inst->param_types[i] == IND_CODE ?
			v = T_IND : 0;
		!(v & o.arg[i]) ?
			inst->invalid = 1 : 0;
	}
}

void	read_dyn_params_types(t_instruction *inst, unsigned char ocp)
{
	t_arg_type	*params_types;
	t_op		o;

	params_types = inst->param_types;
	o = g_op_tab[inst->opcode - 1];
	params_types[0] = ocp >> 6;
	params_types[1] = o.nb_param >= 2 ? (ocp >> 4) & 3 : 0;
	params_types[2] = o.nb_param >= 3 ? (ocp >> 2) & 3 : 0;
	test_valid_param(inst, o);
}
