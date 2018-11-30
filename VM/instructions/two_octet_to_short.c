/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_octet_to_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:09:19 by afourcad          #+#    #+#             */
/*   Updated: 2018/11/30 17:45:07 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

short	two_octets_to_short(unsigned char ram[MEM_SIZE], int pc)
{
	char	tab[2];

	tab[0] = ram[(pc + 1) % MEM_SIZE];
	tab[1] = ram[pc];
	return (*((short*)tab));
}
