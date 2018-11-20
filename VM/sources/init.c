/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:27 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 18:08:45 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void init_vm(t_vm *vm)
{
	int i;

	i = 0;
	vm->nbplayers = 0;
	while (i < MAX_PLAYERS)
	{
		vm->players[i].header = malloc(sizeof(t_header));
		vm->players[i].p = 0;
		vm->players[i].nb_live = 0;
		vm->players[i].last_live = 0;
		i++;
	}
	vm->flag.dump = 0;
	vm->flag.n = 0;
	vm->flag.visu = 0;
	vm->cycle = 0;
	vm->check_cycles = 0;
	vm->cycle_die = 0;
	vm->dump_cycle = 0;
	vm->pause = 0;
}
