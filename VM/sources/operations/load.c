/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:24 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 00:32:14 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	if (ope->param_type[0] == T_IND)
		proc->r[(size_t)ope->param[1] - 1] = to_int(vm, real_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	else
		proc->r[(size_t)ope->param[1] - 1] = to_int(vm, proc->pc + ope->param[0]);
	proc->carry = !ope->param[1]? 1 : 0;
}

void indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[0] == T_REG)
		a = proc->r[(size_t)ope->param[0] - 1];
	else if (ope->param_type[0] == T_IND)
		a = real_pc(proc->pc + (ope->param_type[0] % IDX_MOD));
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = real_pc(proc->pc + (ope->param_type[1] % IDX_MOD));
	else
		b = ope->param[1];
	proc->r[(size_t)ope->param[2] - 1] = to_int(vm, a + b);
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[0] == T_REG)
		a = proc->r[(size_t)ope->param[0] - 1];
	else if (ope->param_type[0] == T_IND)
		a = proc->pc;
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = proc->pc;
	else
		b = ope->param[1];
	proc->r[(size_t)ope->param[2] - 1] = to_int(vm, a + b);
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	proc->r[(size_t)ope->param[1] - 1] = to_int(vm, proc->pc);
	proc->carry = !ope->param[1] ? 1 : 0;
}
