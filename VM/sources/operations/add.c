/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/21 15:04:51 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void add(t_vm *vm, t_proc *proc, t_operation *ope)
{
	ft_putstr("In add\n");
	(void)vm;
	proc->r[(size_t)ope->param[2] - 1] = (proc->r[(size_t)ope->param[1] - 1] 
		+ proc->r[(size_t)ope->param[0] - 1]);
	proc->carry = !proc->r[(size_t)ope->param[2] - 1] ? 1 : 0;
}
