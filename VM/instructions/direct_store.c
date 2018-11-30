/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:57:37 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 18:03:51 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	direct_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	value;

	value = 0;
	if (inst->param_types[1] == IND_CODE)
	{
		vm->ram[mod_adr(proc->pc + 3 + (inst->params[1] % IDX_MOD))] =
			proc->r[inst->params[0] - 1] & 0x000000ff;
		vm->ram[mod_adr(proc->pc + 2 + (inst->params[1] % IDX_MOD))] =
			(proc->r[inst->params[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[mod_adr(proc->pc + 1 + (inst->params[1] % IDX_MOD))] =
			(proc->r[inst->params[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[mod_adr(proc->pc + (inst->params[1] % IDX_MOD))] =
			(proc->r[inst->params[0] - 1] & 0xff000000) >> 24;
		vm->visu ? change_ram_color(vm, proc->pc,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)), proc->id) : 0;
	}
	else
		proc->r[inst->params[1] - 1] = proc->r[inst->params[0] - 1];
}

void	long_direct_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	value;

	value = 0;
	if (inst->param_types[1] == IND_CODE)
	{
		vm->ram[mod_adr(proc->pc + 3 + inst->params[1])] =
			(proc->r[inst->params[0] - 1] & 0x000000ff);
		vm->ram[mod_adr(proc->pc + 2 + inst->params[1])] =
			(proc->r[inst->params[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[mod_adr(proc->pc + 1 + inst->params[1])] =
			(proc->r[inst->params[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[mod_adr(proc->pc + inst->params[1])] =
			(proc->r[inst->params[0] - 1] & 0xff000000) >> 24;
		vm->visu ? change_ram_color(vm, proc->pc,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)), proc->id) : 0;
	}
	else
		proc->r[inst->params[1] - 1] = proc->r[inst->params[0] - 1];
}
