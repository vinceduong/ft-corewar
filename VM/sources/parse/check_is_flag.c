/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:34:27 by vduong            #+#    #+#             */
/*   Updated: 2018/11/25 13:26:24 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_is_flag(char **av, int i)
{
	if (av[i][0] == '-')
	{
		if (!ft_strcmp(av[i], "-dump"))
			return (1);
		else if (!ft_strcmp(av[i], "-n"))
			return (2);
		else if (!ft_strcmp(av[i], "-v"))
			return (3);
		else
			return (-1);
	}
	else
		return (0);
}
