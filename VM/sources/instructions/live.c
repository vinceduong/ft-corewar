/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2018/12/06 16:02:23 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int			i;

	i = 0;
	proc->alive = 1;
	proc->last_cycle_alive = vm->cycles_total;
	vm->lives_current++;
	vm->lives_total++;
	while (i < vm->num_players)
	{
		if (vm->players[i].number == inst->params[0])
		{
			if (vm->show_lives && !vm->visu && vm->dump_cycle == -1)
				ft_printf("Player %d (%s) is said to be alive\n",
					-inst->params[0], vm->players[i].header.prog_name);
			++(vm->players[i].nb_live);
			vm->players[i].last_live = vm->cycles_total;
			vm->winner = i;
			return ;
		}
		++i;
	}
}
