# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/11/30 17:45:34 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft/includes -I ../ft_printf/

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

PRINTF = ../ft_printf/libftprintf.a


SRCS = 	instructions/aff.c\
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
		parser/invalid_int.c\
		parser/load_player.c\
		parser/parser.c\
		./check.c\
		dump.c\
		execute_instruction.c\
		init.c\
		loop.c\
		main.c\
		ocp.c\
		op_functions.c\
		process.c\
		swap.c\
		


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