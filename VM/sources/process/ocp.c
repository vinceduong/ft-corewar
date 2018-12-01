/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:06:30 by lde-moul          #+#    #+#             */
/*   Updated: 2018/11/30 18:02:22 by vduong           ###   ########.fr       */
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

void	ocp_to_param_types(t_instruction *inst, unsigned char ocp)
{
	t_arg_type	*pt;
	t_op		o;

	pt = inst->param_types;
	o = op_tab[inst->opcode - 1];
	pt[0] = ocp >> 6;
	pt[1] = o.nb_param >= 2 ? (ocp >> 4) & 3 : 0;
	pt[2] = o.nb_param >= 3 ? (ocp >> 2) & 3 : 0;
	test_valid_param(inst, o);
}
