/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:34:14 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 10:45:38 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int n;

	i = 0;
	n = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[++n])
		s1[i + n] = s2[n];
	s1[i + n] = s2[n];
	return (s1);
}
