.PHONY : all clean fclean re

CC = gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror

NAME = corewar

INCLUDES = -I ./includes/ -I ../libft

HEADERS = ./includes/vm.h\
		  ./includes/op.h\

LIBFT = ../libft/libft.a

SRCS = ./sources/main.c \
	   ./sources/start.c \
	   ./sources/parse/check_args.c \
	   ./sources/parse/parse.c \
	   ./sources/parse/check_is_flag.c \
	   ./sources/parse/check_is_cor.c \
	   ./sources/parse/check_n.c \
	   ./sources/parse/check_dump.c \
	   ./sources/swap.c \
	   ./sources/parse/fill_players.c \
	   ./sources/init.c \
	   ./sources/error.c \


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
