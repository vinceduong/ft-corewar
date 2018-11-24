/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:01:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/24 09:21:38 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void live(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)ope;
	proc->alive = 1;
	vm->lives++;
	if (ope->param[0] >= 1 && ope->param[0] <= 4)
	{
		if (vm->players[ope->param[0] - 1].p == 1)
		{
			vm->players[ope->param[0] - 1].nb_live++;
			vm->winner = ope->param[0] - 1;
			printf("The player \"%s\" ($%d) is alive !\n",
				vm->players[ope->param[0] - 1].filename, proc->player);
		}
	}
}
