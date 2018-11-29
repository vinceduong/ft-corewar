/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:17 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 15:06:05 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		corewar_fork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	//ft_printf("In fork : adress = %#x\n", mod_pc(proc->pc + (ope->param[0] % IDX_MOD)));
	fork = NULL;
	fork = init_process(vm, mod_pc(proc->pc + (ope->param[0] % IDX_MOD)) ,
		proc->player);
	fork->alive = proc->alive;
	ft_memcpy((void*)proc->r, (void*)fork->r, REG_NUMBER * sizeof(int));
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}

void		lfork(t_vm *vm, t_proc *proc, t_operation *ope)
{
	t_proc *fork;

	//ft_printf("In lfork : adress = %#x\n", mod_pc(proc->pc + ope->param[0])); 
	//ft_printf("%#x %#x\n", ope->param[0], vm->ram[proc->pc - 1].content);
	fork = NULL;
	fork = init_process(vm, mod_pc(proc->pc + ope->param[0]), proc->player);
	ft_memcpy((void*)proc->r, (void*)fork->r, REG_NUMBER * sizeof(int));
	fork->carry = proc->carry;
	fork->alive = proc->alive;
	add_process(&vm->stack, fork);
}
