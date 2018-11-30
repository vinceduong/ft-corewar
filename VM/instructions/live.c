/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:26:21 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 17:45:05 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	int			i;

	i = 0;
	proc->alive = 1;
	vm->num_lives++;
	vm->tot_lives++;
	while (i < vm->num_players)
	{
		if (vm->players[i].number == inst->params[0])
		{
			if (vm->show_lives && !vm->visu && vm->dump_cycle == -1)
				ft_printf("The player \"%s\" ($%d) is in life !\n",
					vm->players[i].header.prog_name, inst->params[0]);
			++(vm->players[i].nb_live);
			vm->players[i].last_live = vm->cycle;
			vm->winner = i;
			return ;
		}
		++i;
	}
}
