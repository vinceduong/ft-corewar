/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:25:35 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 11:25:35 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	fill_player_in_ram(t_case *ram, t_player *player)
{
	unsigned int i;

	i = 0;
	while (i < player->header.prog_size)
	{
		ram[i].content = player->prog[i];
		ram[i].player = player->number;
		i++;
	}
}

static void	init_player(int n, t_vm *vm)
{
	t_player	*player;
	int			pc;

	player = &vm->players[n];
	player->nb_live = 0;
	player->last_live = 0;
	pc = n * MEM_SIZE / vm->num_players;
	fill_player_in_ram(vm->ram + pc, player);
	create_process(vm, pc, player->number, 0);
}

void		init_vm(t_vm *vm)
{
	int	i;

	ft_bzero(vm->ram, MEM_SIZE * sizeof(t_case));
	vm->processes = NULL;
	vm->num_processes = 0;
	i = 0;
	while (i < vm->num_players)
	{
		init_player(i, vm);
		i++;
	}
	vm->cycles_total = 0;
	vm->win = 0;
	vm->winner = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_left = vm->cycles_to_die;
	vm->lives_current = 0;
	vm->lives_total = 0;
	vm->checks_left = MAX_CHECKS;
}
