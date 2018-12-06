# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 11:06:36 by vduong            #+#    #+#              #
#    Updated: 2018/12/06 12:57:02 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

VM = ./VM/corewar

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all : $(LIBFT) $(PRINTF) $(VM)

$(VM) :
	@make -C VM

$(LIBFT) :
	@make -C libft

$(PRINTF) :
	@make -C ft_printf

clean :
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C VM

fclean :
	@make fclean -C libft
	@make fclean -C ft_printf
	@make fclean -C VM

re :
	@make re -C libft
	@make re -C ft_printf
	@make re -C VM

up : all clean
