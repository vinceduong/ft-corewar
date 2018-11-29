/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:13 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/29 15:06:13 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add(t_vm *vm, t_proc *proc, t_operation *ope)
{
	//printf("In add : arg1 = %#x arg2 = %#x\n", proc->r[ope->param[1] - 1] , proc->r[ope->param[0] - 1]);
	(void)vm;
	proc->r[ope->param[2] - 1] = (proc->r[ope->param[1] - 1]
		+ proc->r[ope->param[0] - 1]);
	proc->carry = proc->r[ope->param[2] - 1] == 0 ? 1 : 0;
}
