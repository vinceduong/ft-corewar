/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:20:24 by lde-moul          #+#    #+#             */
/*   Updated: 2017/11/01 17:18:47 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cor_fork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, mod_adr(proc->pc + inst->params[0] % IDX_MOD), 0, 1);
	vm->processes->alive = proc->alive;
	ft_memcpy((void*)vm->processes->r, (void*)proc->r,
			(size_t)REG_NUMBER * sizeof(int));
	vm->processes->carry = proc->carry;
	vm->processes->alive = proc->alive;
}

void	cor_lfork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, mod_adr(proc->pc + inst->params[0]), 0, 1);
	vm->processes->alive = proc->alive;
	ft_memcpy((void*)vm->processes->r, (void*)proc->r,
			(size_t)REG_NUMBER * sizeof(int));
	vm->processes->carry = proc->carry;
	vm->processes->alive = proc->alive;
}
