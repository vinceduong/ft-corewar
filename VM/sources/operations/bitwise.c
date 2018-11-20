/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:47:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 19:31:40 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_and(t_vm *vm, t_proc *proc, t_operation *operation)
{
	int a;
	int b;

	ope->param[0] == T_REG ? a = proc->r[ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = proc->pc + (ope->param[0] % IDX_MOD) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = proc->pc + (ope->param[1] % IDX_MOD) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[ope->param[2]] = a & b;
	proc->carry = proc->r[ope->param[2]] == 0 ? 1 : 0;
}

void corewar_or(t_vm *vm, t_proc *proc, t_operation *operation)
{
	int a;
	int b;

	ope->param[0] == T_REG ? a = proc->r[ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = proc->pc + (ope->param[0] % IDX_MOD) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = proc->pc + (ope->param[1] % IDX_MOD) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[ope->param[2]] = a | b;
	proc->carry = proc->r[ope->param[2]] == 0 ? 1 : 0;
}

void corewar_xor(t_vm *vm, t_proc *proc, t_operation *operation)
{
	int a;
	int b;

	ope->param[0] == T_REG ? a = proc->r[ope->param[0] - 1] : 0;
	ope->param[0] == T_IND ? a = proc->pc + (ope->param[0] % IDX_MOD) : 0;
	ope->param[0] == T_DIR ? a = ope->param[0] : 0;
	ope->param[1] == T_REG ? b = proc->r[ope->param[1] - 1] : 0;
	ope->param[1] == T_IND ? b = proc->pc + (ope->param[1] % IDX_MOD) : 0;
	ope->param[1] == T_DIR ? b = ope->param[1] : 0;
	proc->r[ope->param[2]] = a ^ b;
	proc->carry = proc->r[ope->param[2]] == 0 ? 1 : 0;
}
