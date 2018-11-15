/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:28:42 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/14 18:43:35 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int parser(char **av, t_vm *vm)
{
	int error;

	if ((error = check_args(av)) < 0)
	{
		printf("check_args failed - Error Type = %d \n");
		return (error);
	}
	if ((error = fill_flags(av)) < 0)
	{
		printf("fill_flags failed - Error Type = %d \n");	
		return (error);
	}
	if ((error = fill_players(av, vm)) < 0)
	{
		printf("fill_players failed - Error Type = %d \n");	
		return (error);		
	}
	return (1);
}
