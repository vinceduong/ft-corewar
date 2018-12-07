/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aritmetical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:53:18 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:53:19 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	proc->r[inst->params[2] - 1] =
		proc->r[inst->params[0] - 1] + proc->r[inst->params[1] - 1];
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}

void	sub(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	proc->r[inst->params[2] - 1] =
		proc->r[inst->params[0] - 1] - proc->r[inst->params[1] - 1];
	proc->carry = proc->r[inst->params[2] - 1] == 0 ? 1 : 0;
}
