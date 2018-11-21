/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:14:17 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/25 10:46:52 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	int				n;

	n = 0;
	i = start;
	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len)
	{
		str[n] = s[i];
		if (s[i])
			i++;
		else
			str[n] = '\0';
		n++;
		len--;
	}
	str[n] = '\0';
	return (str);
}
