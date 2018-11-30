/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:19:42 by lde-moul          #+#    #+#             */
/*   Updated: 2017/11/01 16:53:11 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_ncurses(t_vm *vm)
{
	initscr();
	noecho();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, 1);
	vm->speed = 20000;
	vm->pause = 1;
	vm->viewed_process = NULL;
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_WHITE, COLOR_GREEN);
	init_pair(8, COLOR_WHITE, COLOR_RED);
	init_pair(9, COLOR_WHITE, COLOR_YELLOW);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
	display_ram(vm);
}
