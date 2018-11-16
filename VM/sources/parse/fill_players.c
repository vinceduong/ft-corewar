/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:11:44 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 16:42:01 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int fill_player(t_player *player, char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		error("File is not readable\n");
	player->header = malloc(sizeof(t_header));
	if (read(fd, player->header, sizeof(t_header)) != sizeof(t_header))
		error("Header is at wrong format\n");
	if (swap_int(player->header->magic) != COREWAR_EXEC_MAGIC)
		error("Magic number is wrong\n");
	player->header->prog_size = swap_uint(player->header->prog_size);
	player->header->prog_name[PROG_NAME_LENGTH] = '\0';
	player->header->comment[COMMENT_LENGTH] = '\0';
	if (player->header->prog_size > CHAMP_MAX_SIZE)
		error("Program size is too big\n");
	if (read(fd, &player->prog, player->header->prog_size + 1)
	!= player->header->prog_size)
		error("Program size is too big\n");
	close(fd);
	return (1);
}

int fill_players(char **av, t_vm *vm)
{
	int	i;

	i = 0;
	(void)av;
	while (i < MAX_PLAYERS)
	{
		if (vm->players[i].p)
		{
			fill_player(&vm->players[i], vm->players[i].filename);
		}
		i++;
	}
	return (1);
}