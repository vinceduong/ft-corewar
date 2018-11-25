/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:13:10 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/25 13:27:53 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	aff(t_vm *vm, t_proc *proc, t_operation *ope)
{
	char c;

	ft_putstr("In aff\n");
	(void)vm;
	c = proc->r[(size_t)ope->param[0] - 1] % 256;
	ft_putchar(c);
	proc->carry = c == 0 ? 1 : 0;
}
