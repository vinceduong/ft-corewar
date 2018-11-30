/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:04:15 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/19 19:44:12 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	if (!vm->visu)
		ft_printf("%c", proc->r[inst->params[0] - 1] % 256);
	proc->carry = proc->r[inst->params[0] - 1] % 256 == 0 ? 1 : 0;
}
