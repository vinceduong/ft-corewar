/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:53:30 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:53:30 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	direct_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	rel_pc;

	rel_pc = 0;
	if (inst->param_types[0] == IND_CODE)
	{
		rel_pc = mod_adr(proc->pc + (inst->params[0] % IDX_MOD));
		proc->r[inst->params[1] - 1] = read_int(vm->ram, rel_pc);
	}
	else
		proc->r[inst->params[1] - 1] = inst->params[0];
	proc->carry = inst->params[0] == 0 ? 1 : 0;
}

void	long_direct_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	rel_pc;

	rel_pc = 0;
	if (inst->param_types[0] == IND_CODE)
	{
		rel_pc = mod_adr(proc->pc + inst->params[0]);
		proc->r[inst->params[1] - 1] = read_int(vm->ram, rel_pc);
	}
	else
		proc->r[inst->params[1] - 1] = inst->params[0];
	proc->carry = inst->params[0] == 0 ? 1 : 0;
}
