/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:35:29 by vduong            #+#    #+#             */
/*   Updated: 2017/11/17 14:35:31 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ntmp;

	ntmp = (long)n;
	if (ntmp < 0)
	{
		ft_putchar_fd('-', fd);
		ntmp *= -1;
	}
	if ((ntmp / 10) > 0)
		ft_putnbr_fd(ntmp / 10, fd);
	ft_putchar_fd(ntmp % 10 + 48, fd);
}
