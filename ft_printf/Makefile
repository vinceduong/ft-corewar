# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:46:26 by vduong            #+#    #+#              #
#    Updated: 2018/12/06 13:01:08 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

INC = ft_printf.h

SRC =ft_printf.c\
	 ft_text_parser.c\
	 ft_treatement.c\
	 ft_print_chars.c\
	 ft_options.c\
	 ft_option_utilities.c\
	 
HANDLERS =	ft_i.c\
			ft_li.c\
			ft_o.c\
			ft_u.c\
			ft_x.c\
			ft_p.c\
			ft_b.c\
			ft_wstr.c\
			ft_str.c\
			ft_char.c\
			ft_conv_wchar.c\

HANDLERSRC	= $(addprefix handlers/, $(HANDLERS))

OBJ = $(SRC:.c=.o)
HANDLEROBJ = $(HANDLERSRC:.c=.o)

all : $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(HANDLEROBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME) : $(HANDLEROBJ) $(OBJ) libft/*.c libft/Makefile
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar -rc $(NAME) $(OBJ) $(HANDLEROBJ)
	@ranlib $(NAME)
	@echo "\033[32mPRINTF  : libftprintf.a Created\033[0m"

clean :
	@make clean -C libft
	@rm -rf $(OBJ) $(HANDLEROBJ)
	@echo "\033[32mPRINTF  : Object Files Removed\033[0m"

fclean : clean
	@make fclean -C libft
	@rm -rf libftprintf.a
	@echo "\033[32mPRINTF  : libftprintf.a Removed\033[0m"

re : fclean all

.PHONY: all clean fclean re
