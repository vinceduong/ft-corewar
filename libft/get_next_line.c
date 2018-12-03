/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:58:41 by tescriva          #+#    #+#             */
/*   Updated: 2018/12/03 17:27:11 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_gnl(t_list **gnl, int fd)
{
	t_list *tmp;

	tmp = *gnl;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(gnl, tmp);
	tmp = *gnl;
	return (tmp);
}

static int		ft_strfind(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == 0x0a)
			return (i);
	return (-1);
}

static int		ft_return_line(char **line, t_list *lst)
{
	char	*tmp;
	int		i;

	if (!ft_strlen(lst->content))
		return (0);
	i = ft_strfind(lst->content);
	if (i != -1)
	{
		tmp = ft_strnew(i);
		ft_memcpy(tmp, lst->content, i);
		tmp[i] = '\0';
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strdup(lst->content);
		free(lst->content);
		lst->content = ft_strdup(tmp + i + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	*line = ft_strdup(lst->content);
	ft_strclr(lst->content);
	return (1);
}

static char		*ft_join(char *tab, char *tmp)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	tab ? i = ft_strlen(tab) : 0;
	tmp ? j = ft_strlen(tmp) : 0;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	ft_memcpy(str, tab, i);
	ft_memcpy(str + i, tmp, j);
	str[i + j] = '\0';
	free(tab);
	tab = NULL;
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*gnl;
	t_list				*lst;
	char				tmp[BUFF_SIZE + 1];
	int					ret;

	if ((fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0))
		return (-1);
	lst = ft_gnl(&gnl, fd);
	*line = NULL;
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (!(lst->content = ft_join(lst->content, tmp)))
			return (-1);
		if (ft_strchr(tmp, 0x0a))
			break ;
	}
	return (ft_return_line(line, lst));
}
