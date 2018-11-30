/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:41:35 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/26 16:50:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	invalid_int(char *s)
{
	int	len;

	if (*s == '+')
		s++;
	len = ft_strlen(s);
	if (*s != '-' ?
	len > 10 || (len == 10 && ft_strncmp(s, "2147483647", 10) > 0) :
	len > 11 || (len == 11 && ft_strncmp(s, "-2147483648", 11) > 0))
		return (1);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			return (1);
		s++;
	}
	return (0);
}
