# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/12/01 11:19:56 by vduong           ###   ########.fr        #
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


SRCS = 	sources/main.c\
		sources/instructions/aff.c\
		sources/instructions/aritmetical.c\
		sources/instructions/direct_load.c\
		sources/instructions/direct_store.c\
		sources/instructions/fork.c\
		sources/instructions/four_octets_to_int.c\
		sources/instructions/indirect_load.c\
		sources/instructions/indirect_store.c\
		sources/instructions/live.c\
		sources/instructions/logical.c\
		sources/instructions/op.c\
		sources/instructions/op_functions.c\
		sources/instructions/two_octet_to_short.c\
		sources/instructions/zjmp.c\
		sources/parser/invalid_int.c\
		sources/parser/load_player.c\
		sources/parser/parser.c\
		sources/process/check.c\
		sources/process/execute_instruction.c\
		sources/process/loop.c\
		sources/process/ocp.c\
		sources/process/process.c\
		sources/tools/dump.c\
		sources/tools/init.c\
		sources/tools/swap.c\
		
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