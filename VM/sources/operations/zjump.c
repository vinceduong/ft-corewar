/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:45 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/22 17:08:32 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void zjump(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;
	ft_putstr("In zjump\n");
	if (proc->carry == 1)
		proc->pc = ope->pc % MEM_SIZE;
}
