/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:53:10 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/13 16:02:02 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
#include "libft.h"
#include "op.h"
/*
	live	= 0x01 = 	10 	cycles
	ld		= 0x02 = 	5 	cycles
	st 		= 0x03 =	4 	cycles
	add 	= 0x04 = 	10 	cycles
	sub 	= 0x05 =	10 	cycles
	and 	= 0x06 =	6 	cycles
	or 		= 0x07 =	6 	cycles
	xor 	= 0x08 =	6 	cycles
	zjmp 	= 0x09 = 	20 	cycles
	ldi 	= 0x0a =	25 	cycles
	sti 	= 0x0b =	25 	cycles
	fork 	= 0x0c = 	800 cycles
	lld 	= 0x0d = 	10	cycles
	lldi 	= 0x0e =	50	cycles
	lfork 	= 0x0f =	1000	cycles
	aff 	= 0x10 = 	2	cycles

	PART 1 = Number magic = 4bytes;
	PART 2 = NAME = 128byte;
	PART 3 = COMMENt = 2048byte;

	NUMBER MAGIC = 0xea83f3 = (0x00) 0xea 0x83 0xf3


	1byte = 1octet = 8bits;
	instruction = 1 byte = 0000 0000 + value;
	ex = live = 0x01;

	1byte = 1octet = 8bits;
	Encoded byte = 1 byte = 0000 0000 + value;
	ex = r1, 3, %3 = 0111 1000 = 0xB8;

	4 byte = 4octet = 32bit;
	Direct = 4byte = 0000 0000 / 0000 0000 / 0000 0000 / 0000 0000 + value;
	ex = %3 = 0000 0000 / 0000 0000 / 0000 0000 / 0000 0011 = 0x3;

	2 byte = 2octet = 16bit;
	Indirect = 2byte = 00000 0000 / 0000 0000 + value;
	ex = PC = 0 = (PC + 3) = 0000 0000 / 0000 0011 = 0x3;

	1byte = 1octet = 8bits;
	Register = 1byte = 0000 0000 + value;
	ex = r1 = 0000 0001 = 0x01;
*/

typedef struct	s_player
{
	int p[4];
	int nb_live;
	int last_live;
}				t_player;

typedef struct	s_proc
{
	int		r[REG_NUMBER];
	int		id;
	int		carry;
	int		player;
	int		opcode;
	int		cycle;
	int		PC;
	char	*prog;
	void	*next;
}				t_proc;

typedef struct	s_vm
{
	unsigned char ram[MEM_SIZE];
	unsigned char instru[CHAMP_MAX_SIZE];
	t_proc			*process;
	t_player		player[MAX_PLAYERS];
	int cycle;
	int check_cycles;
	int cycle_die;
	int dump_cycle;
	int pause;
}				t_vm;

int ft_parser(char **av, t_vm *vm);
#endif
