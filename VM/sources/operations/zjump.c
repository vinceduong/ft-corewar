/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/25 13:28:51 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	zjump(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = mod_pc(proc->pc + (ope->param[0] % IDX_MOD));
	//ft_printf("Jumping to %d (+%d)\n", proc->pc, ope->param[0]);
	//ft_printf("Instruction at %d = %s : %d %d\n", proc->pc, op_tab[vm->ram[proc->pc].content].name, to_int(vm, vm->ram[proc->pc + 1].content), to_int(vm, vm->ram[proc->pc + 5].content));
}
