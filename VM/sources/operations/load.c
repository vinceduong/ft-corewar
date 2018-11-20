/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:24 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 20:58:18 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	proc->r[ope->param[1] - 1] = (int)vm->ram[proc->pc + (ope->param[0] % IDX_MOD)];
	proc->carry = !ope->param[1] ? 1 : 0;
}

void indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[0] == T_REG)
		a = proc->r[ope->param[0]];
	else if (ope->param_type[0] == T_IND)
		a = proc->pc + (ope->param_type[0] % IDX_MOD);
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = proc->pc + (ope->param_type[1] % IDX_MOD);
	else
		b = ope->param[1];
	proc->r[ope->param[2]] = vm->ram[a + b];
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[0] == T_REG)
		a = proc->r[ope->param[0]];
	else if (ope->param_type[0] == T_IND)
		a = proc->pc;
	else
		a = ope->param[0];
	if (ope->param_type[1] == T_IND)
		b = proc->pc;
	else
		b = ope->param[1];
	proc->r[ope->param[2]] = vm->ram[a + b];
	proc->carry = a + b == 0 ? 1 : 0;
}

void long_direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	proc->r[ope->param[1]] = vm->ram[proc->pc];
	proc->carry = !ope->param[1] ? 1 : 0;
}
