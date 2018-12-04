VM = ./vm/corewar

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all : $(VM) $(LIBFT) $(PRINTF)
	@make -C libft
	@make -C ft_printf
	@make -C vm

clean :
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C vm

fclean :
	@make fclean -C libft
	@make fclean -C ft_printf
	@make fclean -C vm

re :
	@make re -C libft
	@make re -C ft_printf
	@make re -C vm
	