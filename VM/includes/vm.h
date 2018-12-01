/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 20:10:14 by gdelabro          #+#    #+#             */
/*   Updated: 2018/12/01 15:07:08 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H


# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <ncurses.h>

# define MAX_SPEED 1
# define MIN_SPEED 1000000
# define SPEED_STEP 3000
# define DISPLAY_FREQUENCY 100000
# define GLOW_CYCLE 49

typedef struct	s_player
{
	int				number;
	unsigned char	prog[CHAMP_MAX_SIZE];
	t_header		header;
	int				nb_live;
	int				last_live;
}				t_player;

typedef struct	s_instruction
{
	int				opcode;
	int				ocp;
	t_arg_type		param_types[3];
	int				params[3];
	int				invalid;
}				t_instruction;

typedef struct	s_case
{
	unsigned char	content;
	int				player;
	int				glow;
}				t_case;

typedef struct	s_proc
{
	int				r[REG_NUMBER];
	int				pc;
	char			carry;
	int				cycles;
	int				lives;
	int				alive;
	char			opcode;
	int				id;
	struct s_proc	*next;
	struct s_proc	*previous;
}				t_proc;

typedef struct	s_vm
{
	t_case			ram[MEM_SIZE];
	t_proc			*processes;
	int				num_processes;
	int				proc_created;
	int				num_players;
	t_player		players[MAX_PLAYERS];
	int				cycles_to_die;
	int				lives_current;
	int				lives_total;
	int				cycles_left;
	int				checks_left;
	int				cycles_total;
	int				dump_cycle;
	int				show_lives;
	int				win;
	int				visu;
	int				speed;
	int				pause;
	struct timeval	last_display;
	int				sbs;
	t_proc			*viewed_process;
	int				winner;
}				t_vm;


/*
** PARSER
*/
void			parse(int argc, char **argv, t_vm *vm);
void			load_player(t_player *p, const char *name, t_vm *vm);

/*
** GENERAL
*/

int				ft_printf(const char *format, ...);
void			init_vm(t_vm *vm);
void			loop(t_vm *vm);
void			create_process(t_vm *vm, int pc, int player_num, int no_init);
void			kill_process(t_proc *process, t_vm *vm);
void			execute_instruction(t_proc *process, t_vm *vm);
void			load_instruction(t_proc *process, t_vm *vm);
void			ocp_to_param_types(t_instruction *inst, unsigned char ocp);
void			read_dyn_params_types(t_instruction *inst, unsigned char ocp);
void			read_static_params_types(char params_types[3], char arg[3]);
void	read_param_content(t_instruction *inst, int n, 
		t_case ram[MEM_SIZE], int *pc);
int				check_processes(t_vm *vm);
int				invalid_int(char *s);
void			dump_ram(t_vm *vm);
int				swap_int(int n);
unsigned int	swap_uint(unsigned int n);
short			swap_short(short n);
short			read_short(t_case ram[MEM_SIZE], int pc);
int				read_int(t_case ram[MEM_SIZE], int pc);
void			init_ncurses(t_vm *vm);
int				sleep_display(t_vm *vm);
void			display_ram(t_vm *vm);
void			change_ram_color(t_vm *vm, int pc, int pc_dest, int p_id);
void			display_players(t_vm *vm, WINDOW *info, int *line);
void			clear_viewed(t_vm *vm, WINDOW *info, int line);
void			display_winner(t_vm *vm);
void			display_winner_ncurse(t_vm *vm, WINDOW *info, int line);

/*
** INSTRUCTIONS
*/

void			(*g_op_functions[16])(t_vm*, t_proc*, t_instruction*);
void			add(t_vm *vm, t_proc *proc, t_instruction *inst);
void			sub(t_vm *vm, t_proc *proc, t_instruction *inst);
void			log_and(t_vm *vm, t_proc *proc, t_instruction *inst);
void			log_or(t_vm *vm, t_proc *proc, t_instruction *inst);
void			log_xor(t_vm *vm, t_proc *proc, t_instruction *inst);
void			direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			indirect_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_indirect_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_load(t_vm *vm, t_proc *proc, t_instruction *inst);
void			long_direct_store(t_vm *vm, t_proc *proc, t_instruction *inst);
void			live(t_vm *vm, t_proc *proc, t_instruction *inst);
void			zjmp(t_vm *vm, t_proc *proc, t_instruction *inst);
int				mod_adr(int adr);
void			proc_fork(t_vm *vm, t_proc *src, t_instruction *inst);
void			proc_lfork(t_vm *vm, t_proc *src, t_instruction *inst);
void			aff(t_vm *vm, t_proc *proc, t_instruction *inst);

#endif
