/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 15:07:37 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	//ft_putstr("In direct_store\n");
	if (ope->param_type[1] == IND_CODE)
	{
		vm->ram[mod_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].content =
			proc->r[ope->param[0] - 1] & 0x000000ff;
		vm->ram[mod_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].content =
			(proc->r[ope->param[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[mod_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].content =
			(proc->r[ope->param[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[mod_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + (ope->param[1] % IDX_MOD))].content =
			(proc->r[ope->param[0] - 1] & 0xff000000) >> 24;
		vm->ram[mod_pc(proc->pc + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
	}
	else
		proc->r[ope->param[1] - 1] = proc->r[ope->param[0] - 1];
}

void		indirect_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	//ft_putstr("In indirect_store\n");
	if (ope->param_type[1] == REG_CODE)
		a = proc->r[ope->param[1] - 1];
	else if (ope->param_type[1] == IND_CODE)
		a = read_int(vm, mod_pc(proc->pc + (ope->param[1] % IDX_MOD)));
	else
		a = ope->param[1];
	if (ope->param_type[2] == REG_CODE)
		b = proc->r[ope->param[2] - 1];
	else
		b = ope->param[2];
	proc->carry = a + b == 0 ? 1 : 0;
	//printf("pc = %d , write %#x to adress = %d\n", proc->pc, proc->r[ope->param[0] - 1], mod_pc(proc->pc + ((a + b) % IDX_MOD)));
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 3)].content =
		proc->r[ope->param[0] - 1] & 0x000000ff;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 3)].pid =
		proc->player;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 2)].content =
		(proc->r[ope->param[0] - 1] & 0x0000ff00) >> 8;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 2)].pid =
		proc->player;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 1)].content =
		(proc->r[ope->param[0] - 1] & 0x00ff0000) >> 16;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD) + 1)].pid =
		proc->player;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD))].content =
		(proc->r[ope->param[0] - 1] & 0xff000000) >> 24;
	vm->ram[mod_pc(proc->pc + ((a + b) % IDX_MOD))].pid =
		proc->player;
	//printf("ram content at %d = %#x\n", mod_pc(proc->pc + ((a + b) % IDX_MOD)), read_int(vm, mod_pc(proc->pc + ((a + b) % IDX_MOD))));
}
