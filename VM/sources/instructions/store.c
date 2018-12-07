/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:25:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 12:14:20 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	write_int(t_vm *vm, int n, int pc, int player)
{
	vm->ram[mod_adr(pc + 3)].content = n & 0x000000ff;
	vm->ram[mod_adr(pc + 3)].player = player;
	vm->ram[mod_adr(pc + 2)].content = (n & 0x0000ff00) >> 8;
	vm->ram[mod_adr(pc + 2)].player = player;
	vm->ram[mod_adr(pc + 1)].content = (n & 0x00ff0000) >> 16;
	vm->ram[mod_adr(pc + 1)].player = player;
	vm->ram[mod_adr(pc)].content = (n & 0xff000000) >> 24;
	vm->ram[mod_adr(pc)].player = player;
}

void		direct_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	value;
	int adress;

	if (inst->param_types[1] == IND_CODE)
	{
		value = proc->r[inst->params[0] - 1];
		adress = proc->pc + (inst->params[1] % IDX_MOD);
		write_int(vm, value, adress, vm->ram[proc->pc].player);
	}
	else
		proc->r[inst->params[1] - 1] = proc->r[inst->params[0] - 1];
}

void		indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int		param_2;
	int		param_3;
	int		adress;

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
	adress = proc->pc + ((param_2 + param_3) % IDX_MOD);
	write_int(vm, proc->r[inst->params[0] - 1],
		adress, vm->ram[proc->pc].player);
}
