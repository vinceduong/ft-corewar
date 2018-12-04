/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:52:05 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/04 16:12:39 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_get_index(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == COMMENT_CHAR)
		{
			while (str[i] && str[i] != '\n')
				i++;
		}
		else if (str[i] == '"')
			break ;
	}
	return (i);
}

int ft_get_compteur(char *str, int compteur, int j)
{
	while (str[++j])
	{
		if (str[j] == COMMENT_CHAR)
		{
			while (str[j] && str[j] != '\n')
				j++;
		}
		if (str[j] == '"')
			compteur++;
	}
	return (compteur);
}

char *ft_check_length(t_asm *f, char *str, int part)
{
	int i;
	int compteur;

	i = ft_get_index(str, -1);
	compteur = ft_get_compteur(str, 0, i - 1);
	if (compteur == 1 || compteur == 3)
	{
		if (str[i] == '"')
		{
			if (part == 1)
			{
				i > PROG_NAME_LENGTH ?
				error("Champion name too long (Max Length 128)") : 0;
			}
			else if (part == 2)
			{
				i > COMMENT_LENGTH ?
				error("Comment part too long (Max Length 2048)") : 0;
			}
		}
	}
	else
		part == 1 ? error("check name") : error("check comment");
	return (ft_strsub(str, 0, i));
}

void ft_get_length(t_asm *f, char *name, char *comment)
{
	int i;
	int n;
	int val;

	n = 0;
	if (!name || !comment)
		!name ? error("No Name") : error("No Comment");
	while (name[n] && name[n] != '"')
		name[n] == '\n' ? error("No Name") : n++;
	i = 0;
	while (comment[i] && comment[i] != '"')
		comment[i] == '\n' ? error("No Comment") : i++;
	if (comment[i] == '\0' || name[n] == '\0')
		name[n] == '\0' ? error("No Name") : error("No Comment");
	else
	{
		i++;
		n++;
		f->content[NAME] = ft_check_length(f, name + n, 1);
		f->content[COMMENT] = ft_check_length(f, comment + i, 2);
		f->name = n > i ? 1 : 0;
	}
}
