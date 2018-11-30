# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/11/30 18:14:05 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft -I ../ft_printf/

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

PRINTF = ../ft_printf/libftprintf.a


SRCS = 	op.c\
		check.c\
		dump.c\
		execute_instruction.c\
		init.c\
		loop.c\
		main.c\
		ocp.c\
		op_functions.c\
		process.c\
		swap.c\
		instructions/aff.c\
		instructions/aritmetical.c\
		instructions/direct_load.c\
		instructions/direct_store.c\
		instructions/fork.c\
		instructions/four_octets_to_int.c\
		instructions/indirect_load.c\
		instructions/indirect_store.c\
		instructions/live.c\
		instructions/logical.c\
		instructions/two_octet_to_short.c\
		instructions/zjmp.c\
		ncurses/change_ram_color.c\
		ncurses/display.c\
		ncurses/display_players.c\
		ncurses/init.c\
		ncurses/sleep_display.c\
		parser/invalid_int.c\
		parser/load_player.c\
		parser/parser.c\
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADERS) $(PRINTF) 
	@$(CC) $(FLAGS) $(NCURSES) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
	@printf "\033[032mCOREWAR : ./corewar Created\033[0m\n"

$(LIBFT) :
	@make -C ../libft

$(PRINTF) :
	@make -C ../ft_printf

clean :
	@rm -f $(OBJS) $(VISUOBJS)
	@echo "\033[32mCOREWAR : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mCOREWAR : ./corewar Removed\033[0m"

up : all clean

re : fclean all