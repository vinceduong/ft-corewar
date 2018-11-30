/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:23:29 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 18:03:29 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	clear_viewed(t_vm *vm, WINDOW *info, int line)
{
	(void)vm;
	mvwprintw(info, line + 8, 6, "%63c", ' ');
	mvwprintw(info, line + 9, 6, "%63c", ' ');
	mvwprintw(info, line + 10, 6, "%63c", ' ');
	mvwprintw(info, line + 11, 6, "%63c", ' ');
	mvwprintw(info, line + 12, 6, "%63c", ' ');
	mvwprintw(info, line + 13, 6, "%63c", ' ');
	mvwprintw(info, line + 14, 6, "%63c", ' ');
}

int		taille_nb(int nb)
{
	int t;
	int i;

	i = 0;
	t = nb == -2147483648 || !nb ? 1 : 0;
	nb == -2147483648 ? nb = -214748364 : 0;
	nb < 0 ? t += 1 : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (t + i);
}

void	display_winner_ncurse(t_vm *vm, WINDOW *info, int line)
{
	int player_num;

	player_num = vm->winner;
	wmove(info, line + 15, 3);
	wprintw(info, "The winner is:");
	wattron(info, COLOR_PAIR(player_num + 2));
	wattron(info, WA_BOLD);
	wprintw(info, " %.51s",
			vm->players[player_num].header.prog_name);
	wmove(info, line + 17, 3);
	wattroff(info, COLOR_PAIR(player_num + 2));
	wattroff(info, WA_BOLD);
	wprintw(info, "Press ESC to finish.");
}

void	display_players(t_vm *vm, WINDOW *info, int *line)
{
	int players;

	players = 0;
	while (players < vm->num_players)
	{
		mvwprintw(info, *line, 3, "Player (%d): ",
				vm->players[players].number);
		wattron(info, COLOR_PAIR(players + 2));
		wattron(info, WA_BOLD);
		wprintw(info, "%.44s", vm->players[players].header.prog_name);
		wattroff(info, COLOR_PAIR(players + 2));
		wattroff(info, WA_BOLD);
		mvwprintw(info, *line + 1, 5, "Last live %-10d",
				vm->players[players].last_live);
		mvwprintw(info, *line + 2, 5, "Number of live: %-10d",
				vm->players[players].nb_live);
		++players;
		*line = *line + 4;
	}
}
