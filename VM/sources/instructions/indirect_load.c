/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:36:12 by gdelabro          #+#    #+#             */
/*   Updated: 2018/11/30 18:04:00 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;
	int	value;

	if (inst->param_types[0] == REG_CODE)
		param_a = proc->r[inst->params[0] - 1];
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == REG_CODE)
		param_b = proc->r[inst->params[1] - 1];
	else
		param_b = inst->params[1];
	value = four_octets_to_int(vm->ram,
		mod_adr(proc->pc + ((param_b + param_a) % IDX_MOD)));
	proc->r[inst->params[2] - 1] = value;
}

void	long_indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int	param_a;
	int	param_b;
	int	value;

	if (inst->param_types[0] == REG_CODE)
		param_a = proc->r[inst->params[0] - 1];
	else
		param_a = inst->params[0];
	if (inst->param_types[1] == REG_CODE)
		param_b = proc->r[inst->params[1] - 1];
	else
		param_b = inst->params[1];
	value = four_octets_to_int(vm->ram, mod_adr(proc->pc + param_a + param_b));
	proc->r[inst->params[2] - 1] = value;
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}
