/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:50:56 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 17:43:22 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int ac, char **av)
{
	t_vm vm;

	init_vm(&vm);
	if (ac < 2)
	{
		printf("ntm\n");
		return (0);
	}
	/*if (ac == 1)
		ft_error(0);*/
	if (start(&vm, av) == 0)
		//ft_error(1);
	//else
		//ft_exit(&vm, 0);
	return (0);
}
