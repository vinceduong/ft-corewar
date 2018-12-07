# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 11:06:36 by vduong            #+#    #+#              #
#    Updated: 2018/12/07 14:56:36 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

VM = ./VM/corewar

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all :
	@make -C libft
	@make -C ft_printf
	@make -C VM
	@make -C Assembleur

clean :
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C VM
	@make clean -C Assembleur

fclean :
	@make fclean -C libft
	@make fclean -C ft_printf
	@make fclean -C VM
	@make fclean -C Assembleur

re : fclean all

up : all clean
