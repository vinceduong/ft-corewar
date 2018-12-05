/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:26:23 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/05 00:38:10 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_labchar(char c)
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

char *ft_strjoinfree(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

void error(char *str)
{
	ft_putstr("Error : ");
	ft_putstr(str);
	ft_putchar('\n');
	exit (1);
}

void free_the_whole_word(t_asm *f)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_strdel(&f->content[i]);
		i++;
	}
	free(f->content);
	free(f->part);
}

unsigned int	swap_uint(unsigned int n)
{
	return (((n & 0x000000ff) << 24)
		| ((n & 0x0000ff00) << 8)
		| ((n & 0x00ff0000) >> 8)
		| ((n & 0xff000000) >> 24));
}
