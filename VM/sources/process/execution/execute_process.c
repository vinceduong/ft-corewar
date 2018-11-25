/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:54:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/25 13:24:42 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

voids		execution_part2(t_vm *vm, t_proc *proc, t_operation *ope, int *pc)
{
	read_params_content(ope, 0, vm, pc);
	read_params_content(ope, 1, vm, pc);
	read_params_content(ope, 2, vm, pc);
	if (!ope->error)
		ops[ope->opcode - 1](vm, proc, ope);
	if (!(proc->opcode == 9 && proc->carry) || ope->error)
		proc->pc = *pc;
}

void		execute_process(t_vm *vm, t_proc *proc)
{
	t_operation		ope;
	int				pc;

	ft_bzero(&ope, sizeof(t_operation));
	ope.opcode = proc->opcode;
	if (ope.opcode < 1 || ope.opcode > 16)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	pc = mod_pc(proc->pc + 1);
	ope.error = 0;
	if (op_tab[ope.opcode - 1].ocp)
	{
		ope.ocp = vm->ram[pc].content;
		pc =mod_pc(pc + 1);
		read_params_type(&ope, ope.ocp);
	}
	else
		tab_to_type(ope.param_type, op_tab[ope.opcode - 1].arg);
	execution_part2(vm, proc, &ope, &pc);
}
