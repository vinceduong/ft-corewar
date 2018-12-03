/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:52:05 by thescriv          #+#    #+#             */
/*   Updated: 2018/12/03 16:52:20 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void ft_get_comment(f)
{
	int i;
	int n;
	int j;

	n = 0;
	while (f->tab[n])
	{
		if (ft_strstr(f->tab[n], NAME_CMD_STRING))
		{
			while (f->tab[n])
			{
				i = 0;
				while (f->tab[n][i])
				{
					if (f->tab[n][i] == '"')
						f->name++;
					else if (ft_strstr(f->tab[n], COMMENT_CMD_STRING))
						break ;
					else
					{
						f->content[j++] = f->tab[n][i];
						if (j > PROG_NAME_LENGTH)
							error("Champ Name too Long\n")
					}
					i++;
				}
				n++;
			}
			break ;
		}
		n++;
	}
	f->name != 2 ? error("In name\n") : 0;
}

void ft_get_comment(f)
{
	int i;
	int n;
	int j;

	n = 0;
	while (f->tab[n])
	{
		if (ft_strstr(f->tab[n], COMMENT_CMD_STRING))
		{
			while (f->tab[n])
			{
				i = 0;
				while (f->tab[n][i])
				{
					if (f->tab[n][i] == '"')
						f->comment++;
					else if (ft_strstr(f->tab[n], NAME_CMD_STRING))
						break ;
					else
					{
						f->content[j++] = f->tab[n][i];
						if (j > COMMENT_LENGTH)
							error("Champ Comment too Long\n")
					}
					i++;
				}
				n++;
			}
			break ;
		}
		n++;
	}
	f->comment != 2 ? error("In comment\n") : 0;
}