/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 12:19:10 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_fork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;
	
	fork = NULL;
	if (ope->param[0] == 0)
	{
		fork = init_process(vm, proc->pc + (ope->param[0] % IDX_MOD),
			proc->player);
	}
	else
		fork = init_process(vm, proc->pc, proc->player);
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}

void lfork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	fork = NULL;
	if (ope->param[0] == 0)
		fork = init_process(vm, proc->pc, proc->player);
	else
		return ;
	fork->carry = proc->carry;
	fork->alive = proc->alive;
}
