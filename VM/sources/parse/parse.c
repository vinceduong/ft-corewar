/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:08:21 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/19 18:55:24 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int parse(t_vm *vm, char **av)
{
	int error;

	if ((error = check_args(av, vm)) < 0)
	{
		printf("check_args failed - Error Type = %d \n", 1);
		return (error);
	}
	if ((error = fill_players(av, vm)) < 0)
	{
		printf("fill_players failed - Error Type = %d \n", 1);
		return (error);
	}
	return (1);
}
