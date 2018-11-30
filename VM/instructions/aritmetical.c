/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:13:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/19 18:51:59 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
