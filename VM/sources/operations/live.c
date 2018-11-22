/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:01:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 14:23:32 by thescriv         ###   ########.fr       */
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
	ft_printf("The player \"%s\" ($%d) is alive ! ",
		vm->players[proc->player].filename, proc->player);
}
