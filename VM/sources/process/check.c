/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:55:56 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:55:57 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	if (vm->lives_current >= NBR_LIVE || !(--vm->checks_left))
	{
		vm->cycles_to_die = vm->cycles_to_die > CYCLE_DELTA ?
			vm->cycles_to_die - CYCLE_DELTA : 1;
		vm->checks_left = MAX_CHECKS;
	}
	vm->cycles_left = vm->cycles_to_die;
	vm->lives_current = 0;
	return (vm->processes != NULL);
}
