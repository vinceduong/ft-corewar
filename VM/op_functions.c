/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:27:01 by lde-moul          #+#    #+#             */
/*   Updated: 2018/11/30 17:48:04 by vduong           ###   ########.fr       */
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
	cor_and,
	cor_or,
	cor_xor,
	zjmp,
	indirect_load,
	indirect_store,
	cor_fork,
	long_direct_load,
	long_indirect_load,
	cor_lfork,
	aff,
};
