# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/11/24 10:36:38 by vduong           ###   ########.fr        #
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

VISU = ./sources/display/display.c \
		./sources/display/display_winner.c \
		./sources/display/create_visualizer.c

SRCS = 	./sources/tools/error.c\
		./sources/tools/init.c\
		./sources/loop/loop.c\
		./sources/main.c\
		./sources/tools/dump.c\
		./sources/tools/read_int.c\
		./sources/tools/read_short.c\
		./sources/operations/add.c\
		./sources/operations/aff.c\
		./sources/operations/bitwise.c\
		./sources/operations/fork.c\
		./sources/operations/live.c\
		./sources/operations/load.c\
		./sources/operations/sub.c\
		./sources/operations/op.c\
		./sources/operations/store.c\
		./sources/operations/tab_function.c\
		./sources/operations/zjump.c\
		./sources/parse/check_args.c\
		./sources/parse/check_dump.c\
		./sources/parse/check_is_cor.c\
		./sources/parse/check_is_flag.c\
		./sources/parse/check_n.c\
		./sources/parse/fill_players.c\
		./sources/parse/parse.c\
		./sources/process/add_process.c\
		./sources/process/check_stack.c\
		./sources/process/delete_process.c\
		./sources/process/execution.c\
		./sources/process/increment_stack.c\
		./sources/process/init_process.c\
		./sources/tools/swap.c\
		./sources/print/print.c\
		./sources/tools/mod_pc.c\
		


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADERS) $(PRINTF)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
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