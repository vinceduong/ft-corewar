/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:32:36 by vduong            #+#    #+#             */
/*   Updated: 2017/11/17 15:29:30 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(int sign, int count)
{
	if (count == 19 && sign == 1)
		return (-1);
	else if (count == 19 && sign == -1)
		return (0);
	return (1);
}

static	int	ft_finalcheck(unsigned long long n, int sign)
{
	if (n >= 9223372036854775807 && sign == 1)
		return (-1);
	if (n > 9223372036854775807 && sign == -1)
		return (0);
	else
		return (n * sign);
}

int			ft_atoi(const char *nptr)
{
	unsigned long long	n;
	int					sign;
	int					count;

	n = 0;
	sign = 1;
	count = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (ft_check(sign, count) != 1)
			return (ft_check(sign, count));
		n = n * 10 + (*nptr - '0');
		nptr++;
		count++;
	}
	return (ft_finalcheck(n, sign));
}
