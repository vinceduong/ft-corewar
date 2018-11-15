/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:38:02 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/15 14:24:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_start(t_vm *vm, char **av)
{
	if (ft_parser(vm, av) == 0)
		return (0);
	/*if (ft_init_map(vm) == 0)
		return (0);
	if (ft_prepare_champ(vm) == 0)
		return (0);
	if (ft_loop(vm) == 0)
		return (0);
	if (ft_winner(vm) == 0)
		return (0);*/
	char *tmp;
	unsigned char coucou;
	int fd;
	int j = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		int i = -1;
		while (tmp[++i])
		{
			if (j == 4 || j == 128 || j == 2048)
				printf("\n\n" );
			j++;
			coucou = tmp[i];
			printf("%#x ", coucou);
		}
		ft_strdel(&tmp);
	}
	return (1);
}
