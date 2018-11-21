/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:06:32 by thescriv          #+#    #+#             */
/*   Updated: 2018/10/25 15:20:47 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_flag_sc(t_arg *pf)
{
	if (pf->flag[2] != '-' && pf->flag[1])
	{
		while (pf->width-- > 0)
			ft_pf_copy('0', pf);
	}
	while (pf->width-- > 0)
		ft_pf_copy(' ', pf);
}

void	pf_print_wchar(wchar_t *s, t_arg *pf, int i, int size)
{
	char	*tab;

	s == NULL ? s = L"(null)" : 0;
	size = pf->flag[3] && pf->wipr == -1 ? 0 : ft_strwlen(s, pf);
	size == -1 ? pf->ret = -1 : 0;
	if (size == -1)
		return ;
	pf->wipr == -1 && !pf->flag[1] && !pf->flag[3] ? pf->wipr = size : 0;
	pf->wipr > size ? pf->wipr = size : 0;
	pf->width -= pf->wipr > 0 ? pf->wipr : size;
	pf->width > 0 && pf->flag[2] != '-' ? ft_flag_sc(pf) : 0;
	while (pf->wipr > 0)
	{
		i = 0;
		size = ft_charlen(*s);
		tab = size == -1 ? NULL : ft_putwchar(*s, 0);
		tab == NULL ? pf->ret = -1 : 0;
		if (tab == NULL)
			return ;
		pf->wipr -= size;
		while (size-- > 0)
			ft_pf_copy(tab[i++], pf);
		s++;
		free(tab);
	}
}

void	ft_print_s(va_list ag, t_arg *pf)
{
	char	*s;
	int		size;

	if (pf->arg == 's')
	{
		s = va_arg(ag, char*);
		if (s == NULL)
			s = "(null)";
		size = pf->flag[3] && pf->wipr == -1 ? 0 : ft_strlen(s);
		pf->wipr == -1 && (!pf->flag[1] || !pf->flag[3])
		? pf->wipr = size : 0;
		pf->wipr > size ? pf->wipr = size : 0;
		pf->width -= pf->wipr > 0 ? pf->wipr : size;
		pf->width > 0 && pf->flag[2] != '-' ? ft_flag_sc(pf) : 0;
		while (pf->wipr-- > 0)
			ft_pf_copy(*s++, pf);
	}
	else
		pf_print_wchar(va_arg(ag, wchar_t *), pf, 0, 0);
	if (pf->width > 0 && pf->flag[2] == '-')
		ft_flag_sc(pf);
}

void	ft_pf_print_big_c(t_arg *pf, wchar_t c)
{
	int		n;
	char	*tab;

	n = ft_charlen(c);
	tab = n == -1 ? NULL : ft_putwchar(c, 0);
	if (tab == NULL)
	{
		pf->ret = -1;
		return ;
	}
	while (n-- > 0)
	{
		ft_pf_copy(*tab, pf);
		tab++;
	}
}

void	ft_print_c(va_list ag, t_arg *pf)
{
	char		t;
	wchar_t		c;

	pf->arg == 'c' ? t = va_arg(ag, int) : 0;
	pf->arg != 'c' ? c = va_arg(ag, wchar_t) : 0;
	pf->width -= pf->arg == 'c' ? 1 : ft_charlen(c);
	pf->flag[2] != '-' ? ft_flag_sc(pf) : 0;
	if (pf->arg == 'c')
		ft_pf_copy(t, pf);
	else
		ft_pf_print_big_c(pf, c);
	pf->flag[2] == '-' ? ft_flag_sc(pf) : 0;
}
