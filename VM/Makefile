.PHONY : all clean fclean re

CC = gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror

NAME = corewar

INCLUDES = -I ./includes/

LIBFT = ../libft/libft.a

SRCS = ./srcs/main.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "\n\033[032mCOREWAR Compilation Successful\033[0m\n"

$(LIBFT) : 
	make -C ../libft

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all