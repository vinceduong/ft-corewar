/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_next_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:26:30 by vduong            #+#    #+#             */
/*   Updated: 2018/11/27 20:45:21 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		load_next_instruction(t_vm *vm, t_proc *proc)
{
	proc->opcode = vm->ram[proc->pc].content;
	vm->ram[proc->pc].glow = 1;
	proc->cycle = proc->opcode > 0 && proc->opcode <= 16 ?
		op_tab[(int)proc->opcode - 1].cycles : 1;
}
