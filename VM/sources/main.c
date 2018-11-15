/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:50:56 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/15 12:27:25 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int ac, char **av)
{
	t_vm vm;
	
	if (ac < 2)
	{
		printf("ntm\n");
		return (0);
	}
	/*if (ac == 1)
		ft_error(0);*/
	if (ft_start(&vm, av) == 0)
		//ft_error(1);
	//else
		//ft_exit(&vm, 0);
	return (0);
}
