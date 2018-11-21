# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 20:07:22 by thescriv          #+#    #+#              #
#    Updated: 2018/11/21 15:58:30 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = gcc $(INCLUDES) $(FLAGS) 

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

VISU = ./sources/display/display.c \
		./sources/display/display_winner.c \
		./sources/display/create_visualizer.c

SRCS = 	./sources/error.c\
		./sources/init.c\
		./sources/loop/loop.c\
		./sources/main.c\
		./sources/loop/dump.c\
		./sources/oct_to_nb.c\
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
		./sources/swap.c\
		./sources/print/print.c\
		./sources/operations/aim_pc.c\
		


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADERS)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "\n\033[032mCOREWAR Compilation Successful\033[0m\n"

$(LIBFT) :
	make -C ../libft

clean :
	@rm -f $(OBJS)
	make clean -C ../libft

fclean : clean
	@rm -f $(NAME)
	make fclean -C ../libft

up : all clean

re : fclean all
	make re -C ../libft