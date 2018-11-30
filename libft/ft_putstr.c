/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:09:32 by gdelabro          #+#    #+#             */
/*   Updated: 2017/04/25 15:59:24 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putstrw(wchar_t *s)
{
	if (s)
		write(1, s, ft_strlenw(s) * 4);
}
