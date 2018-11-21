/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 14:02:57 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	if (ope->param_type[1] == T_IND)
	{
		vm->ram[proc->pc + 3 + (ope->param[1] % IDX_MOD)].content = 
			proc->r[(size_t)ope->param[0] - 1] & 0x000000ff;
		vm->ram[proc->pc + 3 + (ope->param[1] % IDX_MOD)].pid = 
			proc->player;
		vm->ram[proc->pc + 2 + (ope->param[1] % IDX_MOD)].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[proc->pc + 2 + (ope->param[1] % IDX_MOD)].pid = 
			proc->player;
		vm->ram[proc->pc + 1 + (ope->param[1] % IDX_MOD)].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[proc->pc + 1 + (ope->param[1] % IDX_MOD)].pid = 
			proc->player;
		vm->ram[proc->pc + (ope->param[1] % IDX_MOD)].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0xff000000) >> 24;
		vm->ram[proc->pc + (ope->param[1] % IDX_MOD)].pid = 
			proc->player;	
	}	
	else 
		proc->r[(size_t)ope->param[1] - 1] = proc->r[(size_t)ope->param[0] - 1];
	proc->carry = !proc->r[(size_t)ope->param[0] - 1] ? 1 : 0;
}

void indirect_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[1] == T_REG)
		a = proc->r[(size_t)ope->param[1] - 1];
	else if (ope->param_type[1] == T_IND)
		a = proc->pc + ope->param[1] % IDX_MOD;
	else
		a = ope->param[1];
	if (ope->param_type[2] == T_IND)
		b = proc->pc + ope->param[2] % IDX_MOD;
	else
		b = ope->param[2];
	vm->ram[a + b].content = proc->r[(size_t)ope->param[0] - 1];
	proc->carry = a + b == 0 ? 1 : 0;
}
