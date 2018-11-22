/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 17:07:53 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	ft_putstr("In direct_store\n");
	if (ope->param_type[1] == T_IND)
	{
		vm->ram[real_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].content = 
			proc->r[(size_t)ope->param[0] - 1] & 0x000000ff;
		vm->ram[real_pc(proc->pc + 3 + (ope->param[1] % IDX_MOD))].pid = 
			proc->player;
		vm->ram[real_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0x0000ff00) >> 8;
		vm->ram[real_pc(proc->pc + 2 + (ope->param[1] % IDX_MOD))].pid = 
			proc->player;
		vm->ram[real_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0x00ff0000) >> 16;
		vm->ram[real_pc(proc->pc + 1 + (ope->param[1] % IDX_MOD))].pid = 
			proc->player;
		vm->ram[real_pc(proc->pc + (ope->param[1] % IDX_MOD))].content = 
			(proc->r[(size_t)ope->param[0] - 1] & 0xff000000) >> 24;
		vm->ram[real_pc(proc->pc + (ope->param[1] % IDX_MOD))].pid = 
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

	ft_putstr("In indirect_store\n");
	if (ope->param_type[1] == T_REG)
		a = proc->r[(size_t)ope->param[1] - 1];
	else if (ope->param_type[1] == T_IND)
		a = real_pc(proc->pc + (ope->param[1] % IDX_MOD));
	else
		a = ope->param[1];
	if (ope->param_type[2] == T_IND)
		b = real_pc(proc->pc + (ope->param[2] % IDX_MOD));
	else
		b = ope->param[2];
	vm->ram[a + b].content = proc->r[(size_t)ope->param[0] - 1];
	proc->carry = a + b == 0 ? 1 : 0;
}
