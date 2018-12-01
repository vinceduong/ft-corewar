/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:45:55 by vduong            #+#    #+#             */
/*   Updated: 2017/11/09 09:48:01 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;
	int nres;

	sqrt = 1;
	nres = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (nres < nb)
		{
			sqrt++;
			nres = sqrt * sqrt;
		}
		if (nres != nb)
			return (0);
		return (sqrt);
	}
}
