/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:54:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 15:19:51 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void ocp_to_param_types(t_operation *ope, unsigned char ocp)
{
	ocp == 0xa4 || ocp == 0x94 || ocp == 0xb4 ? ope->param_type[0] = T_IND : 0;
	ocp == 0x54 || ocp == 0x64 ? ope->param_type[0] = t_REG : 0;
	ocp == 0xf4 ? ope->param_type[0] = t_DIR : 0;
	ocp == 0x94 || ocp == 0x54 ? ope->param_type[1] = T_REG : 0;
	ocp == 0xa4 || ocp == 0x64 ? ope->param_type[1] = T_IND : 0;
	ocp == 0xf4 || ocp == 0xb4 ? ope->param_type[1] = T_DIR : 0;
	ocp == 0xa4 || ocp == 0x94 || ocp == 0x54 || ocp == 0x64 || ocp == 0xf4
	|| ocp == 0xb4 ? ope->param_type[2] = T_REG : 0;
}

void ft_get_param(t_operation *ope, int n,
	unsigned char ram[MEM_SIZE], int *pc)
{

}

void execution_part2(t_vm *vm, t_proc *proc, t_operation *ope, int *pc)
{
	ope->param_type[0] = ft_get_param(ope, 0, vm->ram, pc);
	ope->param_type[1] = ft_get_param(ope, 1, vm->ram, pc);
	ope->param_type[2] = ft_get_param(ope, 2, vm->ram, pc);
}

void execution(t_vm *vm, t_proc *proc)
{
	t_operation ope;
	int pc;

	ope->opcode = proc->opcode;
	if (ope->opcode < 1 || ope->opcode > 16)
	{
		++proc->pc %= MEM_SIZE;
		return ;
	}
	pc = (proc->pc + 1) % MEM_SIZE;
	if (op_tab[ope->opcode - 1].ocp)
	{
		ope->ocp = vm->ram[pc];
		++pc %= MEM_SIZE;
		ocp_to_param_types(&ope, ope->ocp);
	}
	execution_part2(vm, proc, &ope, &pc);

}


static void	read_param(t_instruction *inst, int n,
			unsigned char ram[MEM_SIZE], int *pc)
{
	if (!inst->param_types[n])
		return ;
	if (inst->param_types[n] == REG_CODE)
	{
		inst->params[n] = ram[*pc];
		if (inst->params[n] < 1 || inst->params[n] > REG_NUMBER)
			inst->invalid = 1;
		*pc = (*pc + 1) % MEM_SIZE;
	}
	else if (inst->param_types[n] == IND_CODE || op_tab[inst->opcode - 1].d2)
	{
		inst->params[n] = two_octets_to_short(ram, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (inst->param_types[n] == DIR_CODE)
	{
		inst->params[n] = four_octets_to_int(ram, *pc);
		*pc = (*pc + 4) % MEM_SIZE;
	}
}

static void	execute_instruction2(t_instruction *inst, t_proc *proc, int *pc,
		t_vm *vm)
{
	read_param(inst, 0, vm->ram, pc);
	read_param(inst, 1, vm->ram, pc);
	read_param(inst, 2, vm->ram, pc);
	if (!inst->invalid)
		g_op_functions[inst->opcode - 1](vm, proc, inst);
	if (!(inst->opcode == 9 && proc->carry) || inst->invalid)
		proc->pc = *pc;
}
