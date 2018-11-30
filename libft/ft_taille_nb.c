/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taille_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 16:10:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/05 20:14:58 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_taille_nb(long int nb, int base)
{
	int i;

	i = 0;
	while (nb && ++i)
		nb /= base;
	return (i);
}

int		ft_taille_size_t(size_t nb, int base)
{
	int i;

	i = 0;
	while (nb && ++i)
		nb /= base;
	return (i);
}
