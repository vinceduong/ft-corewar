/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:48:26 by vduong            #+#    #+#             */
/*   Updated: 2018/12/06 12:48:27 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_string_size(long long n, int signe)
{
	int	size;

	size = 1 + signe;
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_intmaxtoa(intmax_t n)
{
	intmax_t	result;
	char		*str;
	int			signe;
	int			size;
	int			i;

	signe = 0;
	i = 0;
	result = (long long)n;
	if (result < 0)
		signe = 1;
	if (result < 0)
		result = -result;
	size = ft_string_size(result, signe);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (signe == 1)
		str[0] = '-';
	while (i < size - signe)
	{
		str[size - 1 - i] = result % 10 + 48;
		result = result / 10;
		i++;
	}
	return (str);
}
