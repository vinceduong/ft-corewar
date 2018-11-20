/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:14:27 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 11:58:07 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void fill_ram(t_vm *vm, int adress, int pId)
{
	unsigned int i;

	i = 0;
	printf("PID = %d, adress = %d\n", adress, pId);
	while (i < vm->players[pId].header->prog_size)
	{
		printf("i + adress = %d\n", i + adress);
		vm->ram[i + adress].content = vm->players[pId].prog[i];
		vm->ram[i + adress].pid = pId;
		i++;
	}
}

void init_ram(t_vm *vm)
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
	vm->check_cycles = CYCLE_TO_DIE;
	vm->cycle_die = CYCLE_TO_DIE;
	vm->dump_cycle = 0;
	vm->pause = 0;
}
