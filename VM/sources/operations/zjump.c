/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/23 01:20:02 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void zjump(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	ft_putstr("In zjump\n");
	printf("%d\n", proc->carry);
	if (proc->carry == 1)
		proc->pc = ope->param[0] % MEM_SIZE;
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}
