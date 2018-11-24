# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduong <vduong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:02:33 by vduong            #+#    #+#              #
#    Updated: 2018/11/24 10:38:48 by vduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc $(FLAGS) $(INCLUDES)

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

SRCS = ./ft_atoi.c\
	  ./ft_bzero.c\
	  ./ft_isalnum.c\
	  ./ft_isalpha.c\
	  ./ft_isascii.c\
	  ./ft_isdigit.c\
	  ./ft_isprint.c\
	  ./ft_isdigit.c\
	  ./ft_isprint.c\
	  ./ft_memccpy.c\
	  ./ft_memchr.c\
	  ./ft_memcmp.c\
	  ./ft_memcpy.c\
	  ./ft_memmove.c\
	  ./ft_memset.c\
	  ./ft_strcat.c\
	  ./ft_strchr.c\
	  ./ft_strcmp.c\
	  ./ft_strcpy.c\
	  ./ft_strdup.c\
	  ./ft_strlcat.c\
	  ./ft_strlen.c\
	  ./ft_strncat.c\
	  ./ft_strncmp.c\
	  ./ft_strncpy.c\
	  ./ft_strnstr.c\
	  ./ft_strrchr.c\
	  ./ft_strstr.c\
	  ./ft_strstr.c\
	  ./ft_tolower.c\
	  ./ft_toupper.c\
	  ./ft_memalloc.c\
	  ./ft_memdel.c\
	  ./ft_memalloc.c\
	  ./ft_memdel.c\
	  ./ft_strnew.c\
	  ./ft_strdel.c\
	  ./ft_strclr.c\
	  ./ft_striter.c\
	  ./ft_striteri.c\
	  ./ft_strmap.c\
	  ./ft_strmapi.c\
	  ./ft_strequ.c\
	  ./ft_strnequ.c\
	  ./ft_strsub.c\
	  ./ft_strjoin.c\
	  ./ft_strtrim.c\
	  ./ft_strsplit.c\
	  ./ft_itoa.c\
	  ./ft_putchar_fd.c\
	  ./ft_putstr_fd.c\
	  ./ft_putendl_fd.c\
	  ./ft_putnbr_fd.c\
	  ./ft_putchar.c\
	  ./ft_putstr.c\
	  ./ft_putendl.c\
	  ./ft_putnbr.c\
	  ./ft_lstnew.c \
	  ./ft_lstadd.c \
	  ./ft_lstiter.c\
	  ./ft_lstmap.c \
	  ./ft_lstdelone.c \
	  ./ft_lstdel.c \
	  ./ft_factorial.c \
	  ./ft_sqrt.c \
	  ./ft_power.c \
	  ./ft_min.c \
	  ./ft_max.c \


OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\033[032mLIBFT : libft.a Created\033[0m\n"

all : $(NAME)

clean :
	@/bin/rm -rf $(OBJS)
	@printf "\033[32mLIBFT : Object Files Removed \n\033[0m"

fclean :clean
	@/bin/rm -rf $(NAME)
	@printf "\033[32mLIBFT : libft.a Removed \n\033[0m"

re:fclean all
