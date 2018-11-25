/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/25 13:28:39 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	ft_putstr("In direct_store\n");
	if (ope->param_type[1] == IND_CODE)
	{
		vm->ram[mod_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].content =
			proc->r[(size_t)ope->param[0] - 1] & 0x000000ff;
		vm->ram[mod_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].content =
			(proc->r[(size_t)ope->param[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[mod_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].content =
			(proc->r[(size_t)ope->param[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[mod_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
		vm->ram[mod_pc(proc->pc + (ope->param[1] % IDX_MOD))].content =
			(proc->r[(size_t)ope->param[0] - 1] & 0xff000000) >> 24;
		vm->ram[mod_pc(proc->pc + (ope->param[1] % IDX_MOD))].pid =
			proc->player;
	}
	else
		proc->r[(size_t)ope->param[1] - 1] = proc->r[(size_t)ope->param[0] - 1];
	proc->carry = !proc->r[(size_t)ope->param[0] - 1] ? 1 : 0;
}

void		indirect_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	ft_putstr("In indirect_store\n");
	if (ope->param_type[1] == T_REG)
		a = proc->r[(size_t)ope->param[1] - 1];
	else if (ope->param_type[1] == T_IND)
		a = mod_pc(proc->pc + (ope->param[1] % IDX_MOD));
	else
		a = mod_pc(proc->pc + (ope->param[1] % IDX_MOD));
	if (ope->param_type[2] == T_IND)
		b = mod_pc(proc->pc + (ope->param[2] % IDX_MOD));
	else
		b = mod_pc(proc->pc + (ope->param[2] % IDX_MOD));
	proc->carry = a + b == 0 ? 1 : 0;
	vm->ram[mod_pc(a + b + 3)].content =
		proc->r[(size_t)ope->param[0] - 1] & 0x000000ff;
	vm->ram[mod_pc(a + b + 3)].pid =
		proc->player;
	vm->ram[mod_pc(a + b + 2)].content =
		(proc->r[(size_t)ope->param[0] - 1] & 0x0000ff00) >> 8;
	vm->ram[mod_pc(a + b + 2)].pid =
		proc->player;
	vm->ram[mod_pc(a + b + 1)].content =
		(proc->r[(size_t)ope->param[0] - 1] & 0x00ff0000) >> 16;
	vm->ram[mod_pc(a + b + 1)].pid =
		proc->player;
	vm->ram[mod_pc(a + b)].content =
		(proc->r[(size_t)ope->param[0] - 1] & 0xff000000) >> 24;
	vm->ram[mod_pc(a + b)].pid =
		proc->player;
}
