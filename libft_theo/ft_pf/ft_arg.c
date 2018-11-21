/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:50:37 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:21:41 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_get_cast(t_arg *pf, const char *format, int i)
{
	if (format[i] == 'h' || format[i] == 'l')
	{
		if (format[i + 1] == 'h' || format[i + 1] == 'l')
		{
			format[i] == 'h' ? pf->flag[6] = 'H' : 0;
			format[i] == 'l' ? pf->flag[9] = 'L' : 0;
			i++;
		}
		else
		{
			pf->flag[7] = format[i] == 'h' ? 'h' : pf->flag[7];
			pf->flag[8] = format[i] == 'l' ? 'l' : pf->flag[8];
		}
	}
	pf->flag[11] = format[i] == 'z' ? 'z' : pf->flag[11];
	pf->flag[10] = format[i] == 'j' ? 'j' : pf->flag[10];
	return (i + 1);
}

void	check_flag(t_arg *pf)
{
	if (pf->flag[0] && pf->flag[1] && pf->flag[2]
		&& pf->flag[3] && pf->flag[4] && pf->flag[5])
	{
		pf->flag[3] = 0;
		pf->width += pf->wipr - 3;
	}
	if (pf->flag[5] && pf->flag[4])
		pf->flag[4] = 0;
	if (pf->flag[1] && (pf->flag[3] || pf->flag[2]))
		pf->flag[1] = 0;
}

int		ft_flag(t_arg *pf, const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		pf->flag[0] = format[i] == '#' ? '#' : pf->flag[0];
		pf->flag[1] = format[i] == '0' ? '0' : pf->flag[1];
		pf->flag[2] = format[i] == '-' ? '-' : pf->flag[2];
		pf->flag[3] = format[i] == '.' ? '.' : pf->flag[3];
		pf->flag[4] = format[i] == ' ' ? ' ' : pf->flag[4];
		pf->flag[5] = format[i] == '+' ? '+' : pf->flag[5];
		if (format[i] >= 49 && format[i] <= 57)
		{
			if (pf->wipr < 0 && format[i - 1] != '.')
				pf->width = ft_atoi(format + i);
			else
				pf->wipr = ft_atoi(format + i);
			i += ft_intlen(pf->wipr == -1 ? pf->width : pf->wipr) - 1;
		}
		else if (ft_chrstr("#0-. +hljz", format[i]) == 0)
			break ;
		i += ft_get_cast(pf, format + i, 0);
	}
	check_flag(pf);
	return (i);
}

void	ft_transf_arg(t_arg *pf, char c)
{
	c == 'i' ? pf->arg = 'd' : 0;
	pf->flag[8] && c == 'c' ? pf->arg = 'C' : 0;
	pf->flag[8] && c == 's' ? pf->arg = 'S' : 0;
	if (c == 'U' || c == 'D' || c == 'O')
	{
		pf->flag[8] = 'l';
		pf->arg = c + 32;
	}
	c == 'p' ? pf->flag[0] = '#' : 0;
	pf->arg ? 0 : (pf->arg = c);
}

int		ft_get_arg(va_list ag, t_arg *pf, const char *format)
{
	int i;

	i = 1;
	if (format[i] == '\0')
		return (i);
	i += ft_flag(pf, format + i);
	ft_transf_arg(pf, format[i]);
	if (format[i] == '\0')
		return (i);
	i++;
	ft_print(ag, pf);
	return (i);
}
