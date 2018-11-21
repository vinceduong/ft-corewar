/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:47:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 15:55:02 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_and(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;
	
	(void)vm;
	ope->param[0] == T_REG ? a = proc->r[(size_t)ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = real_pc(proc->pc + (ope->param[0] % IDX_MOD)) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[(size_t)ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = real_pc(proc->pc + (ope->param[1] % IDX_MOD)) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[(size_t)ope->param[2] - 1] = a & b;
	proc->carry = proc->r[(size_t)ope->param[2] - 1] == 0 ? 1 : 0;
}

void corewar_or(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	(void)vm;
	ope->param[0] == T_REG ? a = proc->r[(size_t)ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = real_pc(proc->pc + (ope->param[0] % IDX_MOD)) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[(size_t)ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = real_pc(proc->pc + (ope->param[1] % IDX_MOD)) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[(size_t)ope->param[2] - 1] = a | b;
	proc->carry = proc->r[(size_t)ope->param[2] - 1] == 0 ? 1 : 0;
}

void corewar_xor(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	(void)vm;
	ope->param[0] == T_REG ? a = proc->r[(size_t)ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = real_pc(proc->pc + (ope->param[0] % IDX_MOD)) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[(size_t)ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = real_pc(proc->pc + (ope->param[1] % IDX_MOD)) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[(size_t)ope->param[2] - 1] = a ^ b;
	proc->carry = proc->r[(size_t)ope->param[2] - 1] == 0 ? 1 : 0;
}
