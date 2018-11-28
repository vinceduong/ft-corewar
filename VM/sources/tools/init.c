/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:27 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/28 12:57:28 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fill_ram(t_vm *vm, int adress, int pId)
{
	unsigned int i;

	i = 0;
	printf("PID = %d, adress = %d\n", pId, adress);
	while (i < vm->players[pId].header->prog_size)
	{
		vm->ram[i + adress].content = vm->players[pId].prog[i];
		vm->ram[i + adress].pid = pId + 1;
		i++;
	}
	printf("Mes clous\n");
	add_process(&vm->stack, init_process(vm, adress, pId));
}

void		init_ram(t_vm *vm)
{
	int			i;
	int			adress;

	i = 0;
	printf("nbplayers = %d\n", vm->nbplayers);
	while (i < vm->nbplayers)
	{
		adress = i * MEM_SIZE / vm->nbplayers;
		fill_ram(vm, adress, i);
		i++;
	}
}

void		init_vm(t_vm *vm)
{
	int i;

	i = 0;
	vm->nbplayers = 0;
	while (i < MAX_PLAYERS)
	{
		vm->players[i].header = malloc(sizeof(t_header));
		vm->players[i].p = 0;
		vm->players[i].nb_live = 0;
		i++;
	}
	vm->stack.start = NULL;
	vm->stack.nbprocess = 0;
	vm->flag.dump = -1;
	vm->flag.n = 0;
	vm->flag.visu = 0;
	vm->cycles_total = 0;
	vm->cycles_left = CYCLE_TO_DIE;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->die_rounds_left = MAX_CHECKS;
	vm->pause = 0;
}
