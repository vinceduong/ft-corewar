/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:05:18 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 12:31:56 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_param_content(t_instruction *inst, int n,
			t_case ram[MEM_SIZE], int *pc)
{
	if (!inst->param_types[n])
		return ;
	if (inst->param_types[n] == REG_CODE)
	{
		inst->params[n] = ram[*pc].content;
		if (inst->params[n] < 1 || inst->params[n] > REG_NUMBER)
			inst->invalid = 1;
		*pc = (*pc + 1) % MEM_SIZE;
	}
	else if (inst->param_types[n] == IND_CODE || g_op_tab[inst->opcode - 1].d2)
	{
		inst->params[n] = read_short(ram, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (inst->param_types[n] == DIR_CODE)
	{
		inst->params[n] = read_int(ram, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
}
