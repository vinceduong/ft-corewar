/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:25:48 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:55 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		n;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	n = ft_strlen(s) - 1;
	while (n >= 0 && (s[n] == ' ' || s[n] == '\t' || s[n] == '\n'))
		n--;
	n++;
	str = (char*)malloc(sizeof(char) * (n ? n - i + 1 : 1));
	if (!str)
		return (NULL);
	if (s[i] == '\0')
	{
		str[0] = '\0';
		return (str);
	}
	str = n ? ft_strsub(s, (unsigned int)i, (unsigned int)n - i) : 0;
	return (str);
}
