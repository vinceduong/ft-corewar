/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:15:47 by lde-moul          #+#    #+#             */
/*   Updated: 2018/11/30 17:55:42 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		handle_processes(t_vm *vm)
{
	t_proc	*process;

	process = vm->processes;
	while (process)
	{
		if (!process->cycles)
			pre_execute_instruction(process, vm);
		process->cycles--;
		if (!process->cycles)
			execute_instruction(process, vm);
		process = process->next;
	}
}

void			handle_main_loop(t_vm *vm)
{
	while (1)
	{
		vm->sbs = 0;
		if (!vm->pause || vm->sbs)
		{
			if (vm->cycle == vm->dump_cycle && !vm->visu)
				dump_ram(vm);
			vm->cycle++;
			handle_processes(vm);
			vm->check_cycles--;
			if (!vm->check_cycles && !check_processes(vm))
				break ;
			if (vm->visu)
				usleep(vm->speed);
		}
	}
	vm->win = 1;
	while (vm->visu && getch() != 27)
		;
}
