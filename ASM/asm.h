/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:35 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/30 18:56:15 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

#define ASM_H
#define NAME_SIZE 128;
#define COMMENT_SIZE 2048;

typedef struct	s_asm
{
	int *part;
	char **content;
	char **tab;
	int error;
	int x;
	int y;
}				t_asm;

#endif
