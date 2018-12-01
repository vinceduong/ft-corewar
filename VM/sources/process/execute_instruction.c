/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:31:46 by vduong            #+#    #+#             */
/*   Updated: 2018/12/01 13:31:46 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

static void	tab_to_param_types(char param_types[3], char arg[3])
{
	if (arg[0] == T_REG)
		param_types[0] = REG_CODE;
	else if (arg[0] == T_DIR)
		param_types[0] = DIR_CODE;
	else if (arg[0] == T_IND)
		param_types[0] = IND_CODE;
	else
		param_types[0] = 0;
	if (arg[1] == T_REG)
		param_types[1] = REG_CODE;
	else if (arg[1] == T_DIR)
		param_types[1] = DIR_CODE;
	else if (arg[1] == T_IND)
		param_types[1] = IND_CODE;
	else
		param_types[1] = 0;
	if (arg[2] == T_REG)
		param_types[2] = REG_CODE;
	else if (arg[2] == T_DIR)
		param_types[2] = DIR_CODE;
	else if (arg[2] == T_IND)
		param_types[2] = IND_CODE;
	else
		param_types[2] = 0;
}

static void	read_param(t_instruction *inst, int n,
			t_case ram[MEM_SIZE], int *pc)
{
	if (!inst->param_types[n])
		return ;
	if (inst->param_types[n] == REG_CODE)
	{
		inst->params[n] = ram[*pc].content;
		if (inst->params[n] < 1 || inst->params[n] > REG_NUMBER)
			inst->invalid = 1;
		*pc = (*pc + 1) % MEM_SIZE;
	}
	else if (inst->param_types[n] == IND_CODE || op_tab[inst->opcode - 1].d2)
	{
		inst->params[n] = read_short(ram, *pc);
		*pc = (*pc + 2) % MEM_SIZE;
	}
	else if (inst->param_types[n] == DIR_CODE)
	{
		inst->params[n] = read_int(ram, *pc);
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

void		execute_instruction(t_proc *proc, t_vm *vm)
{
	t_instruction	inst;
	int				pc;

	inst.opcode = proc->opcode;
	if (inst.opcode < 1 || inst.opcode > 16)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	pc = (proc->pc + 1) % MEM_SIZE;
	inst.invalid = 0;
	if (op_tab[inst.opcode - 1].ocp)
	{
		inst.ocp = vm->ram[pc].content;
		pc = (pc + 1) % MEM_SIZE;
		ocp_to_param_types(&inst, inst.ocp);
	}
	else
		tab_to_param_types(inst.param_types, op_tab[inst.opcode - 1].arg);
	execute_instruction2(&inst, proc, &pc, vm);
}

void		pre_execute_instruction(t_proc *proc, t_vm *vm)
{
	proc->opcode = vm->ram[proc->pc].content;
	proc->cycles = proc->opcode > 0 && proc->opcode <= 16 ?
		op_tab[(int)proc->opcode - 1].cycles : 1;
}
