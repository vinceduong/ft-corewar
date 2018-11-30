/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <afourcad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:42:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/11/01 17:03:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	decrease_viewed_process(t_vm *vm)
{
	t_proc	*proc;

	proc = vm->processes;
	while (proc && proc->next != vm->viewed_process)
	{
		proc = proc->next;
	}
	vm->viewed_process = proc;
	display_ram(vm);
}

static void	increase_viewed_process(t_vm *vm)
{
	if (vm->viewed_process)
		vm->viewed_process = vm->viewed_process->next;
	else
		vm->viewed_process = vm->processes;
	display_ram(vm);
}

int			sleep_display(t_vm *vm)
{
	int	key;

	if ((key = getch()) == ' ')
		vm->pause = !vm->pause;
	else if (key == 27)
		return (1);
	else if (key == '=')
		vm->speed = vm->speed > MAX_SPEED + SPEED_STEP ?
			vm->speed - SPEED_STEP : MAX_SPEED;
	else if (key == '-' && vm->speed < MIN_SPEED)
		vm->speed = vm->speed < MIN_SPEED - SPEED_STEP ?
			vm->speed + SPEED_STEP : MIN_SPEED;
	else if (key == ']')
		vm->speed = MAX_SPEED;
	else if (key == '[')
		vm->speed = MIN_SPEED;
	else if (key == 's')
		vm->sbs = 1;
	else if (key == '.')
		decrease_viewed_process(vm);
	else if (key == ',')
		increase_viewed_process(vm);
	return (0);
}
