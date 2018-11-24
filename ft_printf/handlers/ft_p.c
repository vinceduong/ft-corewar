/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 11:20:47 by vduong            #+#    #+#             */
/*   Updated: 2018/09/29 11:21:28 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_p(t_printf *p)
{
	unsigned long	point;

	if (p->txt == 1)
		ft_print_buf(p);
	point = (unsigned long)va_arg(p->ap, void *);
	p->buf = ft_itoabase_u(point, "0123456789abcdef");
	p->size = p->size - ft_strlen(p->buf) - 2;
	p->flag[POUND] = 1;
	p->flag[J] = -5;
	ft_print_x2(p, point, 0);
}
