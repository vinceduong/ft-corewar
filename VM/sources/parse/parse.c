/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:32:04 by vduong            #+#    #+#             */
/*   Updated: 2018/11/16 17:32:19 by vduong           ###   ########.fr       */
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
