/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:26:00 by gdelabro          #+#    #+#             */
/*   Updated: 2017/05/10 19:19:25 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_2(char *s1, const char *s2, int *t)
{
	int n;

	n = 0;
	while (s2[n])
	{
		s1[*t + n] = s2[n];
		n++;
	}
	s1[*t + n] = 0;
	*t += n;
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s1[i])
		i++;
	while (s2[n])
	{
		s1[i + n] = s2[n];
		n++;
	}
	s1[i + n] = 0;
	return (s1);
}
