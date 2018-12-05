# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/12/05 21:49:09 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft/includes -I ../ft_printf/

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

PRINTF = ../ft_printf/libftprintf.a


SRCS = 	sources/main.c\
		sources/instructions/aff.c\
		sources/instructions/aritmetical.c\
		sources/instructions/direct_load.c\
		sources/instructions/direct_store.c\
		sources/instructions/fork.c\
		sources/tools/read_int.c\
		sources/instructions/indirect_load.c\
		sources/instructions/indirect_store.c\
		sources/instructions/live.c\
		sources/instructions/logical.c\
		sources/instructions/op.c\
		sources/instructions/op_functions.c\
		sources/tools/read_short.c\
		sources/instructions/zjmp.c\
		sources/parser/invalid_int.c\
		sources/parser/load_player.c\
		sources/parser/parser.c\
		sources/process/check.c\
		sources/process/execute_instruction.c\
		sources/process/loop.c\
		sources/process/create_process.c\
		sources/process/kill_process.c\
		sources/process/load_instruction.c\
		sources/process/read_dyn_params_types.c\
		sources/process/read_static_params_types.c\
		sources/process/read_param_content.c\
		sources/tools/dump.c\
		sources/tools/init.c\
		sources/tools/swap.c\
		sources/display/display.c\
		sources/display/create_visualizer.c\
		sources/display/display_players.c\
		sources/display/display_pause.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(LIBFT) $(HEADERS) $(PRINTF) 
	@$(CC) $(NCURSES) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
	@printf "\033[032mCOREWAR : ./corewar Created\033[0m\n"

$(LIBFT) :
	@make -C ../libft

$(PRINTF) :
	@make -C ../ft_printf

clean :
	@rm -f $(OBJS)
	@echo "\033[32mCOREWAR : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mCOREWAR : ./corewar Removed\033[0m"

up : all clean

re : fclean all