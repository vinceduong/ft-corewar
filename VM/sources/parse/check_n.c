/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:08:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/16 18:08:14 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int check_n(char **av, int i)
{
	if (!av[i + 1] || !av[i + 2])
		return (-1);
	if(av[i + 1][1])
		return(-1);
	if(ft_atoi(av[i + 1]) < 1 || ft_atoi(av[i + 1]) > 4)
		return (-1);
	if (!check_is_cor(av[i + 2]))
	{
		return (-1);
	}
	return (1);
}
