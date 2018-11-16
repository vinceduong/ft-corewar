/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:39:15 by vduong            #+#    #+#             */
/*   Updated: 2018/11/16 17:41:25 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_dump(char **av, int i)
{
	int j;

	j = 0;
	if (av[i + 1])
	{
		if (ft_strlen(av[i + 1]) > 10)
			return (-1);
		while (av[i  + 1][j])
		{
			if (!ft_isdigit(av[i + 1][j]))
				return (-1);
			j++;
		}
		if (ft_atoi(av[i + 1]) < 0)
			return (-1);
	}
	else
		return (-2);
	return (1);
}