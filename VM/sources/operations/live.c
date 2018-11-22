/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:01:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 15:22:07 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void live(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)ope;
	printf("It's alive\n");
	proc->alive = 1;
	vm->players[proc->player].nb_live++;
	vm->players[proc->player].last_live = vm->cycle;
	vm->nb_lives++;
	printf("The player \"%s\" ($%d) is alive !\n",
		vm->players[proc->player].filename, proc->player);
}
