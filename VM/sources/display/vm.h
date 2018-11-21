/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:53:10 by thescriv          #+#    #+#             */
/*   Updated: 2018/11/20 17:01:00 by vduong           ###   ########.fr       */
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
# include <ncurses.h>
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

	0xa4:	10 10 01 00
	0x94:	10 01 01 00
	0x54:	01 01 01 00
	0x64:	01 10 01 00
	0xf4:	11 11 01 00
	0xb4:	10 11 01 00
*/
#define PHEADER	vm->players[i].header
#define USAGE	"Usage : ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"

typedef struct 	s_operation
{
	int ocp;
	int pc;
	char param_type[3];
	char param[3];
	int error;
}				t_operation;

typedef struct	s_player
{
	char			*filename;
	int				p;
	int				nb_live;
	int				last_live;
	unsigned char	prog[CHAMP_MAX_SIZE];
	t_header		*header;
}				t_player;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				id;
	int				carry;
	int				player;
	int				opcode;
	int				cycle;
	int				pc;
	int				cursor;
	int				alive;
	char			*prog;
	struct s_proc	*next;
	struct s_proc	*previous;
}				t_proc;

typedef struct	s_stack
{
	t_proc	*start;
	t_proc	*end;
	int		nbprocess;
}				t_stack;

typedef struct s_flag
{
	int		dump;
	int		n;
	int		visu;
}				t_flag;

typedef struct	s_case
{
	unsigned char	content;
	int				pid;
	int				color;
	int				glow;

}				t_case;

typedef struct	s_win
{
	WINDOW 		*win;
	WINDOW		*win_left;
	WINDOW		*win_right;
}				t_win;

typedef struct	s_vm
{
	t_case		ram[MEM_SIZE];
	t_stack		stack;
	t_player	players[MAX_PLAYERS];
	t_flag		flag;
	t_win		display;
	int			nbplayers;
	int			cycle;
	int			check_cycles;
	int			cycle_die;
	int			pause;
	int			dump_cycle;
}				t_vm;


void 			loop(t_vm *vm);
/*GENERAL*/
int 			swap_int(int n);
unsigned int	swap_uint(unsigned int n);
void 			init_vm(t_vm *vm);
void 			init_ram(t_vm *vm);
void 			error(char *msg);

/*PARSING*/
int 			parse(t_vm *vm, char **av);
int 			check_args(char **av, t_vm *vm);
int 			check_is_flag(char **av, int i);
int 			check_is_cor(char *str);
int 			check_n(char **av, int i);
int 			check_dump(char **av, int i);
int 			fill_players(char **av, t_vm *vm);

/*PROCESS*/
void			add_process(t_stack *stack, t_proc *proc);
void			delete_process(t_stack *stack, t_proc *proc);
t_proc			*init_process(t_vm *vm, int pc, int player);
void			increment_stack(t_vm *vm);
/*DISPLAY*/
void			display(t_vm *vm, int step);
void    		create_visualizer(t_win *display);
void    		display_winner(t_win *display);

#endif