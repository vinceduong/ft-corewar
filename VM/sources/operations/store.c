/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 20:42:38 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	if (ope->param_type[1] == T_IND)
		vm->ram[proc->pc + (ope->param[1] % IDX_MOD)] = proc->r[ope->param[0]];
	if (ope->param_type[1] == T_REG)
		proc->r[ope->param[1]] = proc->r[ope->param[0]];
	proc->carry = !proc->r[ope->param[0]] ? 1 : 0;
}

void indirect_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	if (ope->param_type[1] == T_REG)
		a = proc->r[ope->param[1]];
	else if (ope->param_type[1] == T_IND)
		a = proc->pc + ope->param[1] % IDX_MOD;
	else
		a = ope->param[1];
	if (ope->param_type[2] == T_IND)
		b = proc->pc + ope->param[2] % IDX_MOD;
	else
		b = ope->param[2];
	vm->ram[a + b] = proc->r[ope->param[0]];
	proc->carry = a + b == 0 ? 1 ; 0;
}
