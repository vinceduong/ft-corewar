/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:47:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 13:10:53 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	corewar_and(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int		a;
	int		b;

	if (ope->param_type[0] == IND_CODE)
		a = read_int(vm,
			mod_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	else if (ope->param_type[0] == REG_CODE)
		a = proc->r[ope->param[0] - 1];
	else
		a = ope->param[0];
	if (ope->param_type[1] == IND_CODE)
		b = read_int(vm,
			mod_pc(proc->pc + (ope->param[1] % IDX_MOD)));
	else if (ope->param_type[1] == REG_CODE)
		b = proc->r[ope->param[1] - 1];
	else
		b = ope->param[1];
	proc->r[ope->param[2] - 1] = a & b;
	proc->carry = proc->r[ope->param[2] - 1] == 0 ? 1 : 0;
}

void	corewar_or(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int		a;
	int		b;

	if (ope->param_type[0] == IND_CODE)
		a = read_int(vm,
			mod_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	else if (ope->param_type[0] == REG_CODE)
		a = proc->r[ope->param[0] - 1];
	else
		a = ope->param[0];
	if (ope->param_type[1] == IND_CODE)
		b = read_int(vm,
			mod_pc(proc->pc + (ope->param[1] % IDX_MOD)));
	else if (ope->param_type[1] == REG_CODE)
		b = proc->r[ope->param[1] - 1];
	else
		b = ope->param[1];
	proc->r[ope->param[2] - 1] = a | b;
	proc->carry = proc->r[ope->param[2] - 1] == 0 ? 1 : 0;
}

void	corewar_xor(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int		a;
	int		b;

	if (ope->param_type[0] == IND_CODE)
		a = read_int(vm,
			mod_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	else if (ope->param_type[0] == REG_CODE)
		a = proc->r[ope->param[0] - 1];
	else
		a = ope->param[0];
	if (ope->param_type[1] == IND_CODE)
		b = read_int(vm,
			mod_pc(proc->pc + (ope->param[1] % IDX_MOD)));
	else if (ope->param_type[1] == REG_CODE)
		b = proc->r[ope->param[1] - 1];
	else
		b = ope->param[1];
	proc->r[ope->param[2] - 1] = a ^ b;
	proc->carry = proc->r[ope->param[2] - 1] == 0 ? 1 : 0;
}
