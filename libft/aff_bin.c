/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:32:26 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/14 17:44:02 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aff_2(unsigned char a)
{
	char	tab[9];
	int		i;

	tab[8] = 0;
	i = 8;
	while (--i >= 0)
	{
		tab[i] = a % 2 + 48;
		a /= 2;
	}
	write(1, tab, 8);
	write(1, " ", 1);
}

void	aff_bin(char *tab)
{
	int i;

	i = -1;
	while (tab[++i])
		aff_2(tab[i]);
	write(1, "\n", 1);
}
