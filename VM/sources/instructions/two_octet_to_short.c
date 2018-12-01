/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_octet_to_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:09:19 by afourcad          #+#    #+#             */
/*   Updated: 2018/12/01 12:03:49 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short	two_octets_to_short(t_case ram[MEM_SIZE], int pc)
{
	char	tab[2];

	tab[0] = ram[(pc + 1) % MEM_SIZE].content;
	tab[1] = ram[pc].content;
	return (*((short*)tab));
}
