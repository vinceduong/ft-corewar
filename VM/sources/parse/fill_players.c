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

	if ((fd = open(file, O_RDONLY) < 0)
		return (-1);
	printf("%lu\n", sizeof(t_header));
	player->header = malloc(sizeof(t_header));
	if (read(fd, player->header, sizeof(t_header)) != sizeof(t_header))
		return (-1);
	printf("OK2\n");
	if (swap_int(player->header->magic) != COREWAR_EXEC_MAGIC)
		return (-1);
	printf("OK3\n");
	player->header->prog_size = swap_uint(player->header->prog_size);
	player->header->prog_name[PROG_NAME_LENGTH] = '\0';
	player->header->comment[COMMENT_LENGTH] = '\0';
	printf("OK4\n");
	if (player->header->prog_size > CHAMP_MAX_SIZE)
		return (-1);
	printf("OK5\n");
	if (read(fd, &player->prog, player->header->prog_size)
	!= player->header->prog_size)
		return (-1);
	printf("OK6\n");
	close(fd);
	return (1);
}

int fill_players(char **av, t_vm *vm)
{
	int			i;

	i = 0;
	(void)av;
	while (i < MAX_PLAYERS)
	{
		printf("HAHAHHAHAHA\n");
		if (vm->players[i].p)
		{
			if (fill_player(&vm->players[i], vm->players[i].filename) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
