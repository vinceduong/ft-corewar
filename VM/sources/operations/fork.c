/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 16:57:47 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_fork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;
	
	ft_putstr("In fork\n");
	fork = NULL;
	if (ope->param[0] != 0)
	{	
		fork = init_process(vm, real_pc(proc->pc + (ope->param[0] % IDX_MOD)) ,
			proc->player);
	}
	else
		fork = init_process(vm, proc->pc,
			proc->player);
	printf("%d\n", fork->cycle);
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}

void lfork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	ft_putstr("In lfork\n");
	(void)ope;
	fork = NULL;
	fork = init_process(vm, proc->pc, proc->player);
	fork->carry = proc->carry;
	fork->alive = proc->alive;
}
