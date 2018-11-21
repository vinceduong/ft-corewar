/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:50:07 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/04 11:21:51 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_pf_itoa_base(uintmax_t n, char *b, int base)
{
	char		*s;
	int			i;

	if (n == 0 || !n)
		return (ft_memalloc(1));
	i = ft_intlen_unsigned(n, base);
	if (!(s = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	s[i] = '\0';
	while (n != 0)
	{
		s[--i] = b[n % base];
		n /= base;
	}
	return (s);
}
