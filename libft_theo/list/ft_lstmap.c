/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:02:14 by tescriva          #+#    #+#             */
/*   Updated: 2018/09/25 10:44:34 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;
	t_list *t;

	if (!lst)
		return (0);
	l = f(lst);
	lst = lst->next;
	t = l;
	while (lst)
	{
		l->next = f(lst);
		l = l->next;
		lst = lst->next;
	}
	return (t);
}
