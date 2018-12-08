/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:06 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/08 16:14:06 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_asm f;

	ft_bzero(&f, sizeof(f));
	if (ac >= 2)
		ft_start(&f, av, ac);
	else
		ft_putendl("usage : ./asm [Exemple.s] [Exemple2.s] ...");
	return (0);
}
