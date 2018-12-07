/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:25:45 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 11:25:46 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	read_int(t_case ram[MEM_SIZE], int pc)
{
	char	tab[4];

	tab[0] = ram[(pc + 3) % MEM_SIZE].content;
	tab[1] = ram[(pc + 2) % MEM_SIZE].content;
	tab[2] = ram[(pc + 1) % MEM_SIZE].content;
	tab[3] = ram[pc].content;
	return (*((int*)tab));
}
