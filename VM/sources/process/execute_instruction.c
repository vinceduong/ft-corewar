/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:31:46 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 12:31:15 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	execute_instruction2(t_instruction *inst, t_proc *proc, int *pc,
		t_vm *vm)
{
	read_param_content(inst, 0, vm->ram, pc);
	read_param_content(inst, 1, vm->ram, pc);
	read_param_content(inst, 2, vm->ram, pc);
	if (!inst->invalid)
		g_op_functions[inst->opcode - 1](vm, proc, inst);
	if (!(inst->opcode == 9 && proc->carry) || inst->invalid)
		proc->pc = *pc;
}

void		execute_instruction(t_proc *proc, t_vm *vm)
{
	t_instruction	inst;
	int				pc;

	inst.opcode = proc->opcode;
	vm->ram[proc->pc].glow = 0;
	if (inst.opcode < 1 || inst.opcode > 16)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	pc = (proc->pc + 1) % MEM_SIZE;
	inst.invalid = 0;
	if (g_op_tab[inst.opcode - 1].ocp)
	{
		inst.ocp = vm->ram[pc].content;
		pc = (pc + 1) % MEM_SIZE;
		read_dyn_params_types(&inst, inst.ocp);
	}
	else
		read_static_params_types(inst.param_types,
			g_op_tab[inst.opcode - 1].arg);
	execute_instruction2(&inst, proc, &pc, vm);
}
