/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:38:02 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 18:08:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int start(t_vm *vm, char **av)
{
	if (parse(vm, av) == 0)
	{
		printf("Parsing failed\n");
		return (0);
	}
	printf("Parsing worked\n");
	/*if (ft_init_map(vm) == 0)
		return (0);
	if (ft_prepare_champ(vm) == 0)
		return (0);
	if (ft_loop(vm) == 0)
		return (0);
	if (ft_winner(vm) == 0)
		return (0);*/
	/*char tmp[1];
	unsigned char coucou;
	int fd;
	int j = 0;
	int n;
	n = 4;
	fd = open(av[1], O_RDONLY);
	while (j < 2192)
	{
		read(fd, tmp, 1);
		j++;
	}
	while (read(fd, tmp, 1))
	{
		coucou = tmp[0];
		tmp[0] == 0 ? printf("0x0 ") : printf("%#x ", coucou);
	}*/
	return (1);
}
