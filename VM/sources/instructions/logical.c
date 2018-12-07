/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:54:50 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:54:51 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	log_and(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[0] % IDX_MOD)));
	else if (inst->param_types[0] == REG_CODE)
		param_a = proc->r[inst->params[0] - 1];
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)));
	else if (inst->param_types[1] == REG_CODE)
		param_b = proc->r[inst->params[1] - 1];
	else
		param_b = inst->params[1];
	proc->r[inst->params[2] - 1] = param_a & param_b;
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}

void	log_or(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[0] % IDX_MOD)));
	else if (inst->param_types[0] == REG_CODE)
		param_a = proc->r[inst->params[0] - 1];
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)));
	else if (inst->param_types[1] == REG_CODE)
		param_b = proc->r[inst->params[1] - 1];
	else
		param_b = inst->params[1];
	proc->r[inst->params[2] - 1] = param_a | param_b;
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}

void	log_xor(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;

	if (inst->param_types[0] == IND_CODE)
		param_a = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[0] % IDX_MOD)));
	else if (inst->param_types[0] == REG_CODE)
		param_a = proc->r[inst->params[0] - 1];
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == IND_CODE)
		param_b = read_int(vm->ram,
			mod_adr(proc->pc + (inst->params[1] % IDX_MOD)));
	else if (inst->param_types[1] == REG_CODE)
		param_b = proc->r[inst->params[1] - 1];
	else
		param_b = inst->params[1];
	proc->r[inst->params[2] - 1] = param_a ^ param_b;
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}
