/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:25:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/01 13:25:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

void	direct_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	value;

	value = 0;
	if (inst->param_types[1] == IND_CODE)
	{
		vm->ram[mod_adr(proc->pc + 3 + (inst->params[1] % IDX_MOD))].content =
			proc->r[inst->params[0] - 1] & 0x000000ff;
		vm->ram[mod_adr(proc->pc + 2 + (inst->params[1] % IDX_MOD))].content =
			(proc->r[inst->params[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[mod_adr(proc->pc + 1 + (inst->params[1] % IDX_MOD))].content =
			(proc->r[inst->params[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[mod_adr(proc->pc + (inst->params[1] % IDX_MOD))].content =
			(proc->r[inst->params[0] - 1] & 0xff000000) >> 24;
	}
	else
		proc->r[inst->params[1] - 1] = proc->r[inst->params[0] - 1];
}

void	indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int		param_2;
	int		param_3;

	if (inst->param_types[1] == IND_CODE)
		param_2 = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)));
	else if (inst->param_types[1] == REG_CODE)
		param_2 = proc->r[inst->params[1] - 1];
	else
		param_2 = inst->params[1];
	if (inst->param_types[2] == REG_CODE)
		param_3 = proc->r[inst->params[2] - 1];
	else
		param_3 = inst->params[2];
	vm->ram[mod_adr(proc->pc + 3 + ((param_2 + param_3) % IDX_MOD))].content =
		proc->r[inst->params[0] - 1] & 0x000000ff;
	vm->ram[mod_adr(proc->pc + 2 + ((param_2 + param_3) % IDX_MOD))].content =
		(proc->r[inst->params[0] - 1] & 0x0000ff00) >> 8;
	vm->ram[mod_adr(proc->pc + 1 + ((param_2 + param_3) % IDX_MOD))].content =
		(proc->r[inst->params[0] - 1] & 0x00ff0000) >> 16;
	vm->ram[mod_adr(proc->pc + ((param_2 + param_3) % IDX_MOD))].content =
		(proc->r[inst->params[0] - 1] & 0xff000000) >> 24;
}