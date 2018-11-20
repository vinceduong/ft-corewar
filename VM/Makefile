# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 08:34:09 by vduong            #+#    #+#              #
#    Updated: 2018/11/20 17:11:49 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CC = gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

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
		./sources/operations/minus.c\
		./sources/operations/op.c\
		./sources/operations/store.c\
		./sources/operations/store_index.c\
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


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADERS)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "\n\033[032mCOREWAR Compilation Successful\033[0m\n"

$(LIBFT) :
	make -C ../libft

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
