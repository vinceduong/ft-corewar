/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:08:57 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/15 12:05:40 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int pos;
	int neg;
	int nb;

	if (!str)
		return (-1);
	neg = 0;
	i = 0;
	pos = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	str[i] == '+' ? pos++ : 0;
	str[i] == '-' ? neg++ : 0;
	neg || pos ? i++ : 0;
	nb = 0;
	while (str[i] <= '9' && str[i] >= '0' && str[i])
	{
		nb = nb + (str[i] - 48);
		str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9' ? nb = nb * 10 : 0;
		i++;
	}
	return (neg == 1 ? (-nb) : (nb));
}
