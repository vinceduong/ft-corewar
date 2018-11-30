/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_octets_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:45:56 by afourcad          #+#    #+#             */
/*   Updated: 2017/10/19 19:44:32 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	four_octets_to_int(unsigned char ram[MEM_SIZE], int pc)
{
	char	tab[4];

	tab[0] = ram[(pc + 3) % MEM_SIZE];
	tab[1] = ram[(pc + 2) % MEM_SIZE];
	tab[2] = ram[(pc + 1) % MEM_SIZE];
	tab[3] = ram[pc];
	return (*((int*)tab));
}
