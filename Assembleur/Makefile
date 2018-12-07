# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 14:30:47 by thescriv          #+#    #+#              #
#    Updated: 2018/12/07 14:57:14 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

NAME = ../asm

INCLUDES = -I ./includes/ -I ../libft/includes -I ../ft_printf/

HEADERS = ./includes/asm.h\
		  ../VM/includes/op.h\

LIBFT = ../libft/libft.a

PRINTF = ../ft_printf/libftprintf.a


SRCS = 	./src/main.c \
		./src/start.c \
		./src/tools.c \
		./src/name_and_comment.c \
		./src/init_file.c \
		./src/ft_program.c \
		./src/ft_ope_arg.c \
		./src/op.c \
		./src/test_arg.c \
		./src/ft_write_to_cor.c \
		./src/swap.c \



OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADERS) $(PRINTF)
	@echo "\033[32mASM     : Object files Created\033[0m"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
	@printf "\033[032mASM     : ./Assembleur/asm Created\033[0m\n"

$(LIBFT) :
	@make -C ../libft

$(PRINTF) :
	@make -C ../ft_printf

clean :
	@rm -f $(OBJS) $(VISUOBJS)
	@echo "\033[32mASM     : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mASM     : ./Assembleur/asm Removed\033[0m"

up : all clean

re : fclean all
