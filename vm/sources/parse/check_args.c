/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:43:59 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/24 10:40:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_get_player(char **av, t_vm *vm)
{
	int i;
	int champ;

	i = 0;
	champ = 0;
	while (av[++i])
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			champ++;
			i += 2;
		}
		else if (check_is_cor(av[i]))
		{
			while (vm->players[vm->nbplayers].p != 0)
				vm->nbplayers++;
			if (vm->players[vm->nbplayers].p == 0)
			{
				vm->players[vm->nbplayers].p = 1;
				vm->players[vm->nbplayers].filename = ft_strdup(av[i]);
				vm->nbplayers = 0;
			}
			champ++;
		}
	}
	vm->nbplayers = champ;
	ft_printf("%d\n", champ);
	return (champ >= 1 && champ <= 4 ? 1 : -1);
}

int ft_check_flag_value(t_vm *vm, char **av, int i, int return_value)
{
	if (return_value == 1)
	{
		if ((return_value = check_dump(av, i)) < 0)
			return (return_value);
		vm->flag.dump = ft_atoi(av[i + 1]);
	}
	else if (return_value == 2)
	{
		if (check_n(av, i) < 0 || vm->players[ft_atoi(av[i + 1]) - 1].p)
			return (-1);
		vm->players[ft_atoi(av[i + 1]) - 1].filename = ft_strdup(av[i + 2]);
		vm->players[ft_atoi(av[i + 1]) - 1].p = 1;
	}
	return (1);
}

int check_args(char **av, t_vm *vm)
{
	int i;
	int return_value;

	i = 1;
	while (av[i])
	{
		if ((return_value = check_is_flag(av, i)) < 0)
			return (-1);
		else if (return_value > 0)
		{
			if (ft_check_flag_value(vm, av, i, return_value) == -1)
				return (-1);
			return_value == 3 ? vm->flag.visu = 1 : 0;
			return_value == 2 ? i +=2 : i++;
		}
		i++;
	}
	if (ft_get_player(av, vm) == -1)
		return (-1);
	return (1);
}
