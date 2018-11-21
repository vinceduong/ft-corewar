/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:52:59 by thescriv          #+#    #+#             */
/*   Updated: 2018/09/25 11:53:07 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_putwchar(wchar_t c, int i)
{
	char	*tab;

	tab = ft_memalloc(4);
	if (c <= 0xFF)
		tab[i++] = c;
	else if (c <= 0x7FF)
	{
		tab[i++] = (c >> 6) + 0xC0;
		tab[i++] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		tab[i++] = (c >> 12) + 0xE0;
		tab[i++] = ((c >> 6) & 0x3F) + 0x80;
		tab[i++] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		tab[i++] = (c >> 18) + 0xF0;
		tab[i++] = ((c >> 12) & 0x3F) + 0x80;
		tab[i++] = ((c >> 6) & 0x3F) + 0x80;
		tab[i++] = (c & 0x3F) + 0x80;
	}
	i > MB_CUR_MAX ? ft_strdel(&tab) : 0;
	return (tab);
}
