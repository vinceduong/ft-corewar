/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:44:11 by afourcad          #+#    #+#             */
/*   Updated: 2017/11/01 16:09:40 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
