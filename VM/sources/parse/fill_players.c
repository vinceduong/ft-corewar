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

int get_info(t_player *info, char *file)
{
	//int ret;
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	/*ret = read(fd, &info->header, sizeof(t_header));
	printf("%d %lu\n", ret, sizeof(t_header));*/
	printf("%lu\n", sizeof(t_header));
	info->header = malloc(sizeof(t_header));
	if (read(fd, info->header, sizeof(t_header)) != sizeof(t_header))
		return (-1);
	printf("OK2\n");
	if (swap_int(info->header->magic) != COREWAR_EXEC_MAGIC)
		return (-1);
	printf("OK3\n");
	info->header->prog_size = swap_uint(info->header->prog_size);
	info->header->prog_name[PROG_NAME_LENGTH] = '\0';
	info->header->comment[COMMENT_LENGTH] = '\0';
	printf("OK4\n");
	if (info->header->prog_size > CHAMP_MAX_SIZE)
		return (-1);
	printf("OK5\n");
	if (read(fd, &info->prog, info->header->prog_size)
	!= info->header->prog_size)
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
			if (get_info(&vm->players[i], vm->players[i].filename) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
