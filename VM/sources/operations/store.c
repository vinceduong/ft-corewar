/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:39 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/30 15:31:03 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		direct_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int adress;

	if (ope->param_type[1] == IND_CODE)
	{
		// printf("ope->param = %d\n", ope->param[1]);
		adress = proc->pc + (ope->param[1] % IDX_MOD);
		write_int(vm, adress, proc->r[ope->param[0] - 1], proc->player);
	}
	else
		proc->r[ope->param[1] - 1] = proc->r[ope->param[0] - 1];
}

void		indirect_store(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;
	int result;
	int adress;

	if (ope->param_type[1] == REG_CODE)
		a = proc->r[ope->param[1] - 1];
	else if (ope->param_type[1] == IND_CODE)
		a = read_int(vm, mod_pc(proc->pc + (ope->param[1] % IDX_MOD)));
	else
		a = ope->param[1];
	printf("a = %d\n", a);
	if (ope->param_type[2] == REG_CODE)
		b = proc->r[ope->param[2] - 1];
	else
		b = ope->param[2];
	printf("b = %d\n", b);
	result = a + b;
	proc->carry = result == 0 ? 1 : 0;
	adress = proc->pc + (result % IDX_MOD);
	printf("result = %d\n", result % IDX_MOD);
	write_int(vm, adress, proc->r[ope->param[0] - 1], proc->player);
}
