/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:54:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 14:33:06 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void ocp_to_param_types(t_operation *ope, unsigned char ocp)
{
	ocp == 0xa4 || ocp == 0x94 || ocp == 0xb4 ? ope->param_type[0] = T_IND : 0;
	ocp == 0x54 || ocp == 0x64 ? ope->param_type[0] = T_REG : 0;
	ocp == 0xf4 ? ope->param_type[0] = T_DIR : 0;
	ocp == 0x94 || ocp == 0x54 ? ope->param_type[1] = T_REG : 0;
	ocp == 0xa4 || ocp == 0x64 ? ope->param_type[1] = T_IND : 0;
	ocp == 0xf4 || ocp == 0xb4 ? ope->param_type[1] = T_DIR : 0;
	ocp == 0xa4 || ocp == 0x94 || ocp == 0x54 || ocp == 0x64 || ocp == 0xf4
	|| ocp == 0xb4 ? ope->param_type[2] = T_REG : 0;
}

void ft_get_param(t_operation *ope, int n, t_vm *vm, int *pc)
{
	if (ope->param_type[n])
		return ;
	if (ope->param_type[n] == REG_CODE)
	{
		ope->param[n] = vm->ram[*pc].content;
		if (ope->param[n] < 1 || ope->param[n] > REG_NUMBER)
			ope->error = 1;
		*pc = (*pc + 1) % MEM_SIZE;
	}
	else if (ope->param_type[n] == IND_CODE || op_tab[ope->opcode - 1].d2)
	{
		ope->param[n] = to_short(vm, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (ope->param_type[n] == DIR_CODE)
	{
		ope->param[n] = to_int(vm, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
}

void execution_part2(t_vm *vm, t_proc *proc, t_operation *ope, int *pc)
{
	(void)proc;
	ft_get_param(ope, 0, vm, pc);
	ft_get_param(ope, 1, vm, pc);
	ft_get_param(ope, 2, vm, pc);
	if (!ope->error)
		ops[ope->opcode - 1](vm, proc, ope);
	if (!(ope->opcode == 9 && proc->carry) || ope->error)
		proc->pc = *pc;
}

void execution(t_vm *vm, t_proc *proc)
{
	t_operation ope;
	int pc;

	ope.opcode = proc->opcode;
	if (ope.opcode < 1 || ope.opcode > 16)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	pc = (proc->pc + 1) % MEM_SIZE;
	if (op_tab[ope.opcode - 1].ocp)
	{
		ope.ocp = vm->ram[pc].content;
		pc = (pc + 1) % MEM_SIZE;
		ocp_to_param_types(&ope, ope.ocp);
	}
	execution_part2(vm, proc, &ope, &pc);
}
