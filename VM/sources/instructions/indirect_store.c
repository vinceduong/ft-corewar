/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:36:04 by gdelabro          #+#    #+#             */
/*   Updated: 2018/12/01 12:02:46 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int		param_2;
	int		param_3;

	if (inst->param_types[1] == IND_CODE)
		param_2 = four_octets_to_int(vm->ram,
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
