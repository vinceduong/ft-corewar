/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:08:21 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 16:46:05 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int parse(t_vm *vm, char **av)
{
	int error_nb;

	if ((error_nb = check_args(av, vm)) < 0)
	{
		error("check_args failed\n");
	}
	if ((error_nb = fill_players(av, vm)) < 0)
	{
		error("fill_players failed\n");
	}
	return (1);
}
