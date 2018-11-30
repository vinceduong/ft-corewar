/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:51:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/11/01 17:04:17 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_pc(t_vm *vm)
{
	t_proc *proc;

	proc = vm->processes;
	while (proc)
	{
		attron(COLOR_PAIR(vm->ram_color[proc->pc] + 5));
		mvprintw(proc->pc / 64 + 1, proc->pc % 64 * 3 + 2, "%.2x",
				vm->ram[proc->pc]);
		attroff(COLOR_PAIR(vm->ram_color[proc->pc] + 5));
		proc = proc->next;
	}
	proc = vm->viewed_process;
	if (proc)
	{
		attron(COLOR_PAIR(11));
		attron(A_BOLD);
		attron(A_UNDERLINE);
		mvprintw(proc->pc / 64 + 1, proc->pc % 64 * 3 + 2, "%.2x",
			vm->ram[proc->pc]);
		attroff(A_UNDERLINE);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(11));
	}
}

void	display_viewed_process(t_vm *vm, WINDOW *info, int line)
{
	t_proc *p;

	p = vm->viewed_process;
	clear_viewed(vm, info, line);
	if (vm->viewed_process)
	{
		mvwprintw(info, line + 7, 3, "Viewed process: %-10d", p->id);
		mvwprintw(info, line + 8, 6, "Reg: [%x][%x][%x][%x]",
				p->r[0], p->r[1], p->r[2], p->r[3]);
		mvwprintw(info, line + 9, 6, "Reg: [%x][%x][%x][%x]", p->r[4], p->r[5],
				p->r[6], p->r[7]);
		mvwprintw(info, line + 10, 6, "Reg: [%x][%x][%x][%x]", p->r[8], p->r[9],
				p->r[10], p->r[11]);
		mvwprintw(info, line + 11, 6, "Reg: [%x][%x][%x][%x]", p->r[12],
				p->r[13], p->r[14], p->r[15]);
		mvwprintw(info, line + 12, 6, "Cycles: %-4d", p->cycles);
		mvwprintw(info, line + 13, 6, "Carry: %d", p->carry);
		mvwprintw(info, line + 14, 6, "Alive: %d", p->alive);
	}
	else
		mvwprintw(info, line + 7, 3, "Viewed process: None      ");
}

void	display_info(t_vm *vm)
{
	WINDOW	*info;
	int		line;

	line = 13;
	info = subwin(stdscr, 66, 70, 0, 195);
	box(info, ACS_VLINE, ACS_HLINE);
	mvwprintw(info, 3, 3, "Current_cycle: %d", vm->cycle);
	mvwprintw(info, 4, 3, "Cycle before checks: %-4d", vm->check_cycles);
	mvwprintw(info, 6, 3, "Current_live: %-10d", vm->num_lives);
	mvwprintw(info, 8, 3, "Processes alive: %-10d", vm->num_processes);
	mvwprintw(info, 9, 3, "Processes created: %-10d", vm->proc_created);
	mvwprintw(info, 11, 3, "Last live color: ");
	wattron(info, COLOR_PAIR(vm->winner + 7));
	mvwprintw(info, 11, 21, "   ");
	wattroff(info, COLOR_PAIR(vm->winner + 6));
	display_players(vm, info, &line);
	mvwprintw(info, line + 1, 3, "Cycle to Die: %-4d", vm->cycle_to_die);
	mvwprintw(info, line + 3, 3, "Cycle Delta: %d", CYCLE_DELTA);
	mvwprintw(info, line + 5, 3, "Total_live: %d", vm->tot_lives);
	display_viewed_process(vm, info, line);
	vm->win ? display_winner_ncurse(vm, info, line + 5) : 0;
	wrefresh(info);
	delwin(info);
}

void	display_ram_win(WINDOW *ram, int i, int j, t_vm *vm)
{
	int		pc;

	box(ram, ACS_VLINE, ACS_HLINE);
	pc = 0;
	while (++i < 65 && (j = 2))
	{
		move(i, 2);
		while (j < 193)
		{
			!(vm->viewed_process && vm->viewed_process->id
					== vm->ram_viewed[pc])
			? attron(COLOR_PAIR(vm->ram_color[pc])) : attron(COLOR_PAIR(12));
			vm->ram_glow[pc] ? attron(WA_BOLD) : 0;
			printw("%.2x ", vm->ram[pc]);
			vm->ram_glow[pc] ? attroff(WA_BOLD) : 0;
			!(vm->viewed_process && vm->viewed_process->id
					== vm->ram_viewed[pc])
			? attroff(COLOR_PAIR(vm->ram_color[pc])) : attroff(COLOR_PAIR(12));
			++pc;
			j += 3;
		}
	}
}

void	display_ram(t_vm *vm)
{
	WINDOW	*ram;
	int		i;
	int		j;

	ram = subwin(stdscr, 66, 195, 0, 0);
	i = 0;
	j = 2;
	display_ram_win(ram, i, j, vm);
	display_info(vm);
	display_pc(vm);
	curs_set(0);
	refresh();
	delwin(ram);
}
