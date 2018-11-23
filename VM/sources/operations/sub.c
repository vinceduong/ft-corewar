/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:32 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/23 16:28:21 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void sub(t_vm *vm, t_proc *proc, t_operation *ope)
{
	(void)vm;

	//ft_putstr("In sub\n");
	proc->r[(size_t)ope->param[2] - 1] = proc->r[(size_t)ope->param[1] - 1]
		- proc->r[(size_t)ope->param[0] - 1];
	proc->carry = !proc->r[(size_t)ope->param[2] - 1] ? 1 : 0;
}
