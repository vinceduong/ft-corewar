/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:11:44 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/15 18:32:43 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int fill_players(char **av, t_vm *vm)
{
	int			i;
	int			fd;

	i = 0;
	(void)av;
	while (i < MAX_PLAYERS)
	{
		printf("HAHAHHAHAHA\n");
		if (vm->players[i].p)
		{
			fd = open(vm->players[i].filename, O_RDONLY);
			printf("OK1\n");
			if (read(fd, &vm->players[i].header, sizeof(t_header)) != sizeof(t_header))
				return (-1);
			printf("OK2\n");
			if (swap_int(PHEADER.magic) != COREWAR_EXEC_MAGIC)
				return (-1);
			printf("OK3\n");
			PHEADER.prog_size = swap_uint(PHEADER.prog_size);
			PHEADER.prog_name[PROG_NAME_LENGTH] = '\0';
			PHEADER.comment[COMMENT_LENGTH] = '\0';
			printf("OK4\n");
			if (PHEADER.prog_size > CHAMP_MAX_SIZE)
				return (-1);
				printf("OK5\n");
			vm->players[i].instruction = ft_memalloc(PHEADER.prog_size + 1);
			if (read(fd, vm->players[i].instruction, PHEADER.prog_size + 1)
			!= PHEADER.prog_size)
				return (-1);
				printf("OK6\n");
			close(fd);
		}
		i++;
	}
	return (1);
}
