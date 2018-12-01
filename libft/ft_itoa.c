/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:33:35 by vduong            #+#    #+#             */
/*   Updated: 2017/11/17 14:33:36 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_size(long n)
{
	size_t size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	long	ntmp;
	char	*itoa;
	size_t	size;

	ntmp = (long)n;
	size = n_size(ntmp);
	itoa = ft_strnew(size);
	if (!itoa)
		return (NULL);
	if (ntmp < 0)
	{
		*itoa = '-';
		ntmp *= (-1);
	}
	while ((size && n >= 0) || (size > 1 && n < 0))
	{
		itoa[--size] = ntmp % 10 + 48;
		ntmp /= 10;
	}
	return (itoa);
}
