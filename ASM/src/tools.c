/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:26:23 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/06 18:29:56 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_labchar(char c)
{
	int i;

	i = -1;
	while (LABEL_CHARS[++i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
	}
	return(0);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

void	error(char *str)
{
	ft_putstr("Error : ");
	ft_putstr(str);
	ft_putchar('\n');
	exit (1);
}
