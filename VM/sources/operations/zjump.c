/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/23 18:45:43 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void zjump(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = real_pc(proc->pc + (ope->param[0] % IDX_MOD));
	//printf("Jumping to %d (+%d)\n", proc->pc, ope->param[0]);
	//printf("Instruction at %d = %s : %d %d\n", proc->pc, op_tab[vm->ram[proc->pc].content].name, to_int(vm, vm->ram[proc->pc + 1].content), to_int(vm, vm->ram[proc->pc + 5].content));
}
