/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:27:01 by lde-moul          #+#    #+#             */
/*   Updated: 2018/12/01 11:15:14 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*) =
{
	live,
	direct_load,
	direct_store,
	add,
	sub,
	log_and,
	log_or,
	log_xor,
	zjmp,
	indirect_load,
	indirect_store,
	proc_fork,
	long_direct_load,
	long_indirect_load,
	proc_lfork,
	aff,
};
