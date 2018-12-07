/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:52:06 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 17:06:17 by thescriv         ###   ########.fr       */
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

static int	check_file_name(const char *name)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (!ft_strcmp(name + i, ".cor"))
			return (1);
		i++;
	}
	return (0);
}

void		load_player(t_player *p, const char *name, t_vm *vm)
{
	int	file;

	check_player_number(p->number, vm);
	file = open(name, O_RDONLY | O_NOFOLLOW);
	if (file < 0)
		error("Can't open \"%s\"\n", name);
	if (!check_file_name(name))
		error("\"%s\" is not a .cor file !\n", name);
	if (read(file, &p->header, sizeof(t_header)) != sizeof(t_header))
		error("\"%s\" is too short\n", name);
	if (swap_int(p->header.magic) != COREWAR_EXEC_MAGIC)
		error("Invalid magic number in \"%s\"\n", name);
	p->header.prog_size = swap_uint(p->header.prog_size);
	p->header.prog_name[PROG_NAME_LENGTH] = '\0';
	p->header.comment[COMMENT_LENGTH] = '\0';
	if (p->header.prog_size > CHAMP_MAX_SIZE)
		error("\"%s\" is too long\n", name);
	if (read(file, p->prog, p->header.prog_size + 1) != p->header.prog_size)
		error("\"%s\" is corrupted\n", name);
	close(file);
}
