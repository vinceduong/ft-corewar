/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:42:32 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/05 17:14:40 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlen_2(char *s, int i)
{
	int i2;

	i2 = i;
	while (s[++i2])
		;
	return (i2);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_strlenw(wchar_t *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
