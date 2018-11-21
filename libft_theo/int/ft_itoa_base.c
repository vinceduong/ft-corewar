/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:17:15 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/04 11:21:37 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa_base(int n, char *b)
{
	char		*s;
	int			i;
	long		j;
	int			base;

	if (n == 0 || !n)
		return (ft_memalloc(1));
	base = ft_strlen(b);
	j = (long)n;
	n < 0 ? j *= -1 : 0;
	i = ft_intlen_base(j, base);
	if (!(s = (char*)malloc(sizeof(*s) * (n < 0 ? ++i : i))))
		return (NULL);
	s[i] = '\0';
	n < 0 ? s[0] = '-' : 0;
	while (j != 0)
	{
		s[--i] = b[j % base];
		j /= base;
	}
	return (s);
}
