/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:43:59 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 10:13:57 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_args(char **av, t_vm *vm)
{
	int i;
	int return_value;

	i = 1;
	while (av[i])
	{
		if ((return_value = check_is_flag(av, i)) < 0)
			return (return_value);
		else if (return_value)
		{
			if (!ft_strcmp(av[i], "-n"))
			{
				if (check_n(av, i) < 0)
					error(USAGE);
				if (vm->players[ft_atoi(av[i + 1]) - 1].p)
					error("Player number already taken\n");
				vm->players[ft_atoi(av[i + 1]) - 1].filename = ft_strdup(av[i + 2]);
				vm->players[ft_atoi(av[i + 1]) - 1].p = 1;
				vm->nbplayers++;
				i += 2;
			}
			else if (!ft_strcmp(av[i], "-dump"))
			{
				if ((return_value = check_dump(av, i)) < 0)
					return (return_value);
				vm->flag.dump = ft_atoi(av[i + 1]);
				i++;
			}
			else
			{
				if (check_is_cor(av[i]))
				{
					vm->players[vm->nbplayers].p = 1;
					vm->players[vm->nbplayers].filename = ft_strdup(av[i]);
					vm->nbplayers++;
				}
			}
		}
		i++;
	}
	return (1);
}
