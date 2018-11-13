VM = ./vm/corewar

ASM = ./asm/asm

LIBFT = libft/libft.a

all : $(VM) $(ASM) $(LIBFT)
	make -C libft
	make -C vm
	make -C asm

clean :
	make clean -C libft
	make clean -C vm
	make clean -C asm

fclean :
	make fclean -C libft
	make fclean -C vm
	make fclean -C asm

re :
	make re -C libft
	make re -C vm
	make re -C asm
	