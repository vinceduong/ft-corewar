/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:09 by lde-moul          #+#    #+#             */
/*   Updated: 2018/11/30 17:47:39 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	error(const char *msg, const char *name)
{
	ft_printf(msg, name);
	exit(1);
}

static void	check_player_number(int number, t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->num_players)
	{
		if (number == vm->players[i].number)
		{
			ft_printf("Duplicate player number %d\n", number);
			exit(1);
		}
		i++;
	}
}

void		load_player(t_player *p, const char *name, t_vm *vm)
{
	int	file;

	check_player_number(p->number, vm);
	file = open(name, O_RDONLY);
	if (file < 0)
		error("Can't open \"%s\"\n", name);
	if (read(file, &p->header, sizeof(t_header)) != sizeof(t_header))
		error("\"%s\" is too short\n", name);
	if (swap_int(p->header.magic) != COREWAR_EXEC_MAGIC)
		error("Invalid magic number in \"%s\"", name);
	p->header.prog_size = swap_uint(p->header.prog_size);
	p->header.prog_name[PROG_NAME_LENGTH] = '\0';
	p->header.comment[COMMENT_LENGTH] = '\0';
	if (p->header.prog_size > CHAMP_MAX_SIZE)
		error("\"%s\" is too long\n", name);
	if (read(file, p->prog, p->header.prog_size + 1) != p->header.prog_size)
		error("\"%s\" is corrupted\n", name);
	close(file);
}
