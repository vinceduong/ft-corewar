/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 16:59:40 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void corewar_fork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	ft_putstr("In fork\n");
	fork = NULL;
	fork = init_process(vm, real_pc(proc->pc + (ope->param[0] % IDX_MOD)) ,
		proc->player);
	ft_memcpy((void*)proc->r, (void*)fork->r, (size_t)REG_NUMBER * sizeof(int));
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}

void lfork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	ft_putstr("In lfork\n");
	fork = NULL;
	fork = init_process(vm, real_pc(proc->pc + ope->param[0]), proc->player);
	ft_memcpy((void*)proc->r, (void*)fork->r, (size_t)REG_NUMBER * sizeof(int));
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}
