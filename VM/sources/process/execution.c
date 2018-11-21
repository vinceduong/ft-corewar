/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:54:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 00:38:40 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void ocp_to_type(t_operation *ope, unsigned char ocp)
{
	t_arg_type *type;
	t_op		op;
	int i;
	int v;

	i = -1;
	type = ope->param_type;
	op = op_tab[ope->opcode - 1];
	type[0] = ocp >> 6;
	type[1] = op.nb_param >= 2 ? (ocp >> 4) & 3 : 0;
	type[2] = op.nb_param >= 3 ? (ocp >> 2) & 3 : 0;
	while (++i < op.nb_param)
	{
		v = 0;
		if (ope->param_type[i] == REG_CODE)
			v = T_REG;
		else if (ope->param_type[i] == DIR_CODE)
			v = T_DIR;
		else if (ope->param_type[i] == IND_CODE)
			v = T_IND;
		!(v & op.arg[i]) ? ope->error = 1 : 0;
	}
}

void	tab_to_type(char param_types[3], char arg[3])
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

	ft_bzero(&ope, sizeof(t_operation));
	ope.opcode = proc->opcode;
	if (ope.opcode < 1 || ope.opcode > 16)
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	printf("MY OPCODE IS = %d\n", ope.opcode);
	printf("%#x\n", vm->ram[proc->pc].content);
	pc = (proc->pc + 1) % MEM_SIZE;
	ope.error = 0;
	if (op_tab[ope.opcode - 1].ocp)
	{
		ope.ocp = vm->ram[pc].content;
		pc = (pc + 1) % MEM_SIZE;
		ocp_to_type(&ope, ope.ocp);
	}
	else
		tab_to_type(ope.param_type, op_tab[ope.opcode - 1].arg);
	execution_part2(vm, proc, &ope, &pc);
}

void load_next_instruction(t_vm *vm, t_proc *proc)
{
	printf("%#x\n", vm->ram[proc->pc].content);
	proc->opcode = vm->ram[proc->pc].content;
	proc->cycle = proc->opcode > 0 && proc->opcode <= 16 ?
		op_tab[(int)proc->opcode - 1].cycles : 1;
}
