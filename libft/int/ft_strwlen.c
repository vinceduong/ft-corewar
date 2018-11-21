/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:47:16 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:26:21 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				ft_strwlen(wchar_t *str, t_arg *pf)
{
	int i;
	int n;
	int j;
	int width;

	i = 0;
	n = 0;
	width = pf->wipr != -1 ? pf->wipr : -1;
	while (str[i] != '\0')
	{
		j = ft_charlen(str[i]);
		if (j == -1 || (j > MB_CUR_MAX && width < 0))
			return (-1);
		else if (width > 0 && j > width)
			return (n);
		width -= j;
		n += j;
		i++;
	}
	return (n);
}
