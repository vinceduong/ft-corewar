/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:22:18 by tescriva          #+#    #+#             */
/*   Updated: 2018/11/05 12:07:09 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		n;

	n = -1;
	if (!s1 || !s2)
		return (NULL);
	s = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = (char)s1[i];
	while (s2[++n])
		s[i + n] = (char)s2[n];
	s[i + n] = (char)s2[n];
	return (s);
}
