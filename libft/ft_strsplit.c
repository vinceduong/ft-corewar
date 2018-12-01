/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:51:44 by vduong            #+#    #+#             */
/*   Updated: 2017/11/17 14:52:42 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_newsplit(size_t size)
{
	char	**split;

	if (!(split = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	split[size] = NULL;
	while (size--)
		((unsigned char *)split)[size] = 0;
	return (split);
}

static size_t	ft_nbline(char const *s, char c)
{
	size_t nbline;

	nbline = 0;
	while (*s)
	{
		if (*s != c && (*(s - 1) == c || !*(s - 1)))
			nbline++;
		s++;
	}
	return (nbline);
}

static size_t	ft_sizeofline(char const *s, char c)
{
	size_t size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	if (!(split = ft_newsplit(ft_nbline(s, c))))
		return (NULL);
	while (*s)
	{
		if ((*(s - 1) == c || !*(s - 1)) && *s != c)
		{
			if (!(split[++i] = ft_strnew(ft_sizeofline(s, c))))
				return (NULL);
			j = 0;
		}
		if (*s != c)
			split[i][j++] = *s;
		s++;
	}
	return (split);
}
