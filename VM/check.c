/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:11:49 by lde-moul          #+#    #+#             */
/*   Updated: 2017/11/01 16:43:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_processes(t_vm *vm)
{
	t_proc	*process;
	t_proc	*next;

	process = vm->processes;
	while (process)
	{
		next = process->next;
		if (process->alive)
			process->alive = 0;
		else
			kill_process(process, vm);
		process = next;
	}
	if (vm->num_lives >= NBR_LIVE || !(--vm->checks))
	{
		vm->cycle_to_die = vm->cycle_to_die > CYCLE_DELTA ?
			vm->cycle_to_die - CYCLE_DELTA : 1;
		vm->checks = MAX_CHECKS;
	}
	vm->check_cycles = vm->cycle_to_die;
	vm->num_lives = 0;
	return (vm->processes != NULL);
}
