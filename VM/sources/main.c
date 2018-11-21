/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:50:56 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 15:01:53 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int main(int ac, char **av)
{
	t_vm vm;
 
	//printf("salut mes couiilees\n");
	ft_bzero(&vm, sizeof(vm));
	//printf("salut mes couiilees\n");
	init_vm(&vm);
	//printf("salut mes couiilees\n");
	if (ac < 2 || !parse(&vm, av))
		error(USAGE);
	init_ram(&vm);
	printf("salut mes couiilees\n");
	loop(&vm);
	printf("salut mes couiilees\n");
	return (0);
}
