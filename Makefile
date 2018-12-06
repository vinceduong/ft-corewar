VM = ./vm/corewar

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all : $(LIBFT) $(PRINTF) $(VM) 

$(VM):
	@make -C vm

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C ft_printf

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