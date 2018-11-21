/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:50:25 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 11:50:29 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_pf_itoa(intmax_t n)
{
	char		*s;
	int			i;
	intmax_t	j;

	if (n == 0 || n == 1 || !n)
	{
		s = (char*)malloc(sizeof(char) * 2);
		s[0] = n == 1 ? '1' : '0';
		s[1] = '\0';
		return (s);
	}
	j = (intmax_t)n;
	n < 0 ? j *= -1 : 0;
	i = ft_intlen(j);
	s = (char*)malloc(sizeof(*s) * i);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (j > 0)
	{
		s[--i] = (j % 10) + '0';
		j /= 10;
	}
	return (s);
}
