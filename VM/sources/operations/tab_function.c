/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:59:49 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 18:17:46 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	(*ops[16])(t_vm*, t_proc*, t_operation*) =
{
	live,
	direct_load,
	direct_store,
	add,
	sub,
	corewar_and,
	corewar_or,
	corewar_xor,
	zjump,
	indirect_load,
	indirect_store,
	corewar_fork,
	long_direct_load,
	long_indirect_load,
	lfork,
	aff,
};
