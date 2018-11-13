/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:28:42 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/13 16:02:16 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm.h"

char	*ft_strjoinfree(char *to_free, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*tmp;

	if (!to_free || !s2)
		return (NULL);
	i = -1;
	j = -1;
	tmp = ft_strdup(to_free);
	free(to_free);
	size = (int)ft_strlen(tmp) + (int)ft_strlen(s2);
	to_free = (char *)malloc(sizeof(char) * (size + 1));
	if (!to_free)
		return (NULL);
	while (tmp[++i] != '\0')
		to_free[i] = tmp[i];
	while (s2[++j] != '\0')
		to_free[i + j] = s2[j];
	to_free[size] = '\0';
	free(tmp);
	return (&to_free[0]);
}

char		*ft_read_data(int fd)
{
	char *line;
	char *str;

	str = ft_memalloc(1);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n\0");
		ft_strdel(&line);
	}
	return (str);
}

void ft_check_hex(int fd, char *str, t_vm *vm)
{
	char **tab;

	tab = ft_strsplit(ft_read_data(fd), '\n');
	printf("%s\n", tab[0]);
}

int ft_parser(char **av, t_vm *vm)
{
	int i;

	i = 1;
	while (av[i])
	{
		int fd;
		fd = open(av[i], O_RDONLY);
		ft_check_hex(fd, av[i], vm);
		close(fd);
	}
}
