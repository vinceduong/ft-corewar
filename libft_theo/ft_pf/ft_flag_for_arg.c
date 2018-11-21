/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_for_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:35:11 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:20:51 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

intmax_t	ft_cast_d(va_list ag, t_arg *pf)
{
	intmax_t nb;

	nb = va_arg(ag, intmax_t);
	if (pf->flag[10] == 'j')
		return ((intmax_t)nb);
	else if (pf->flag[11] == 'z')
		return ((size_t)nb);
	else if (pf->flag[9] == 'L')
		return ((long long)nb);
	else if (pf->flag[8] == 'l')
		return ((long)nb);
	else if (pf->flag[7] == 'h')
		return ((short)nb);
	else if (pf->flag[6] == 'H')
		return ((char)nb);
	else
		return ((int)nb);
	return (nb);
}

uintmax_t	ft_cast_unsigned(va_list ag, t_arg *pf)
{
	uintmax_t nb;

	nb = va_arg(ag, uintmax_t);
	if (pf->flag[10] == 'j')
		return ((uintmax_t)nb);
	else if (pf->flag[11] == 'z')
		return ((size_t)nb);
	else if (pf->flag[9] == 'L')
		return ((unsigned long long)nb);
	else if (pf->flag[8] == 'l')
		return ((unsigned long)nb);
	else if (pf->flag[7] == 'h')
		return ((unsigned short)nb);
	else if (pf->flag[6] == 'H')
		return ((unsigned char)nb);
	else
	{
		return (nb = pf->arg == 'u' || pf->arg == 'x' || pf->arg == 'X'
		? (unsigned int)nb : (unsigned long long)nb);
	}
	return (nb);
}

void		ft_pf_flag_sign(t_arg *pf, int n)
{
	if (pf->flag[0] && (pf->arg == 'x' || pf->arg == 'p' || pf->arg == 'X'
				|| pf->arg == 'o'))
	{
		ft_pf_copy('0', pf);
		if (pf->arg == 'x' || pf->arg == 'p' || pf->arg == 'X')
			ft_pf_copy(pf->arg == 'x' || pf->arg == 'p' ? 'x' : 'X', pf);
	}
	else if (pf->arg == 'd' || pf->arg == 'D')
	{
		n == 0 ? ft_pf_copy('-', pf) : 0;
		pf->flag[4] && n == 1 ? ft_pf_copy(' ', pf) : 0;
		pf->flag[5] && n == 1 ? ft_pf_copy('+', pf) : 0;
	}
	if (pf->flag[2] == '-' && (pf->flag[1] || pf->flag[3])
	&& (pf->wipr > 0 || pf->width > 0))
	{
		while (pf->wipr-- > 0)
			ft_pf_copy('0', pf);
	}
}

void		ft_pf_reduce_width(t_arg *pf, int i, int n)
{
	(pf->flag[5] || pf->flag[4]) && n == 1 ? pf->width-- : 0;
	n == 0 && (pf->flag[1] || pf->flag[3]) ? pf->wipr -= i - 1
		: (pf->wipr -= i);
	pf->wipr < 0 ? pf->width -= i : (pf->width -= pf->wipr + i);
	if (pf->flag[0] && (pf->arg == 'x' || pf->arg == 'p' || pf->arg == 'X'
				|| pf->arg == 'o'))
	{
		pf->width > 1 && pf->wipr > 1 && pf->flag[0] && pf->arg == 'o'
			? pf->width++ : 0;
		pf->flag[5] = 0;
		pf->flag[4] = 0;
		pf->width -= pf->arg == 'o' ? 1 : 2;
		pf->wipr -= pf->arg == 'o' ? 1 : 0;
	}
	else
		pf->flag[0] = 0;
}

void		ft_handle_flag(int n, t_arg *pf, int i, int nb)
{
	if (nb == 0 && pf->wipr <= -1 && pf->flag[3] == '.')
		;
	else
		ft_pf_reduce_width(pf, i, n);
	if (pf->flag[2] != '-')
	{
		if (pf->flag[1] != '0' && pf->width > 0)
		{
			while (pf->width-- > 0)
				ft_pf_copy(' ', pf);
		}
		ft_pf_flag_sign(pf, n);
		if ((pf->flag[1] || pf->flag[3]) && (pf->wipr > 0 || pf->width > 0))
		{
			while (pf->wipr-- > 0 || pf->width-- > 0)
				ft_pf_copy('0', pf);
		}
	}
	else
		ft_pf_flag_sign(pf, n);
}
