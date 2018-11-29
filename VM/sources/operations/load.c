/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:24 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 15:06:23 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int pc;

	//ft_putstr("In direct_load\n");
	if (ope->param_type[0] == IND_CODE)
	{
		pc = mod_pc(proc->pc + (ope->param[0] % IDX_MOD));
		proc->r[ope->param[1] - 1] = read_int(vm, pc);
	}
	else
		proc->r[ope->param[1] - 1] = ope->param[0];
	proc->carry = !ope->param[0] ? 1 : 0;
}

void		indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	//ft_putstr("In indirect_load\n");
	if (ope->param_type[0] == REG_CODE)
		a = proc->r[ope->param[0] - 1];
	else
		a = ope->param[0];
	if (ope->param_type[1] == REG_CODE)
		b = proc->r[ope->param[1] - 1];
	else
		b = ope->param[1];
	proc->r[ope->param[2] - 1] = read_int(vm, mod_pc(proc->pc + ((a + b) % IDX_MOD)));
}

void		long_indirect_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int a;
	int b;

	//ft_putstr("In long_indirect_load\n");
	if (ope->param_type[0] == REG_CODE)
		a = proc->r[ope->param[0] - 1];
	else
		a = ope->param[0];
	if (ope->param_type[1] == REG_CODE)
		b = proc->r[ope->param[1] - 1];
	else
		b = ope->param[1];
	proc->r[ope->param[2] - 1] = read_int(vm, mod_pc(proc->pc + a + b));
	proc->carry = proc->r[ope->param[2] - 1] == 0 ? 1 : 0;
}

void		long_direct_load(t_vm *vm, t_proc *proc, t_operation *ope)
{
	int pc;

	//ft_putstr("In direct_load\n");
	if (ope->param_type[0] == IND_CODE)
	{
		pc = mod_pc(proc->pc + ope->param[0]);
		proc->r[ope->param[1] - 1] = read_int(vm, pc);
	}
	else
		proc->r[ope->param[1] - 1] = ope->param[0];
	proc->carry = !ope->param[0] ? 1 : 0;
}
