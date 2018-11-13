/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:28:42 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/13 17:00:16 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"

void ft_check_hex(int fd, char *str, t_vm *vm)
{
	char **tab;

	tab = ft_strsplit(ft_read_data(fd), '\n');
	
}

int ft_parser(char **av, t_vm *vm)
{
	int i;

	i = 1;
	while (av[i])
	{
		int fd;
		fd = open(av[i], O_RDONLY);
		ft_check_hex(fd, av[i], vm);
		close(fd);
	}
}