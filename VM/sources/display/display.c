/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aetchego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:39:30 by aetchego          #+#    #+#             */
/*   Updated: 2018/12/10 18:39:37 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_choose_color(int player)
{
	if (player == 0)
		attron(COLOR_PAIR(3));
	else if (player == 1)
		attron(COLOR_PAIR(1));
	else if (player == 2)
		attron(COLOR_PAIR(4));
	else if (player == 3)
		attron(COLOR_PAIR(7));
	else if (player == 4)
		attron(COLOR_PAIR(8));
}

void	print_ram(t_case *ram)
{
	int i;
	int len;
	int line;

	i = 0;
	line = 2;
	move(line, 4);
	while (i < 4096)
	{
		len = 0;
		while (len < 64)
		{
			ft_choose_color(ram[i].player * -1);
			printw("%.2x ", ram[i]);
			len++;
			i++;
		}
		line++;
		move(line, 4);
	}
	refresh();
}

void	move_clear_print(int x, int y, int print)
{
	move(x, y);
	clrtoeol();
	move(x, y);
	printw("%d", print);
}

void	print_infos(t_vm *vm)
{
	int margin_top;
	int margin_left;

	margin_top = 20;
	margin_left = (COLS / 3) * 2 + 32;
	attron(COLOR_PAIR(5));
	move_clear_print(margin_top, margin_left, vm->num_players);
	move_clear_print(margin_top + 4, margin_left, vm->num_processes);
	move_clear_print(margin_top + 8, margin_left, vm->lives_current);
	move_clear_print(margin_top + 12, margin_left, vm->cycles_to_die);
	move_clear_print(margin_top + 16, margin_left, vm->cycles_left);
	move_clear_print(margin_top + 20, margin_left, vm->cycles_total);
	move_clear_print(margin_top + 24, margin_left, vm->checks_left);
	refresh();
}

void	display(t_vm *vm)
{
	display_pause(vm);
	usleep(vm->speed);
	print_ram(vm->ram);
	print_infos(vm);
	print_players_share(vm);
}
