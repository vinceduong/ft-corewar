/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:44:11 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 17:45:08 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		mod_adr(int adr)
{
	adr %= MEM_SIZE;
	while (adr < 0)
		adr += MEM_SIZE;
	return (adr);
}

void	zjmp(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	(void)vm;
	if (proc->carry == 1)
		proc->pc = mod_adr(proc->pc + inst->params[0] % IDX_MOD);
}
