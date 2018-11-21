# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 19:08:17 by tescriva          #+#    #+#              #
#    Updated: 2018/10/25 15:25:19 by thescriv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT = int/ft_atoi.c \
	int/ft_intlen.c \
	int/ft_intlen_base.c \
	int/ft_itoa_base.c \
	int/ft_itoa.c \
	int/ft_putnbr.c \
	int/ft_strlen.c \
	int/ft_strwlen.c \
	int/ft_pf_itoa_base.c \
	int/ft_pf_itoa.c \
	int/ft_intlen_unsigned.c \
	int/ft_charlen.c \
	char/ft_chrstr.c \
	char/ft_putwchar.c \
	char/ft_isalnum.c \
	char/ft_isalpha.c \
	char/ft_isascii.c \
	char/ft_isdigit.c \
	char/ft_isprint.c \
	char/ft_putchar.c \
	char/ft_tolower.c \
	char/ft_toupper.c \
	list/ft_lstadd.c \
	list/ft_lstdel.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstmap.c \
	list/ft_lstnew.c \
	mem/ft_memalloc.c \
	mem/ft_memccpy.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memdel.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	mem/ft_bzero.c \
	mem/ft_strdup.c \
	mem/ft_strndup.c \
	mem/ft_strcdup.c \
	fd/ft_putchar_fd.c \
	fd/ft_putendl_fd.c \
	fd/ft_putnbr_fd.c \
	fd/ft_putstr_fd.c \
	fd/get_next_line.c \
	fd/ft_read_data.c \
	string/ft_strequ.c \
	string/ft_striter.c \
	string/ft_strjoin.c \
	string/ft_strjoinfree.c \
	string/ft_strlcat.c\
	string/ft_strmap.c \
	string/ft_strmapi.c \
	string/ft_strncat.c \
	string/ft_strncmp.c \
	string/ft_strncpy.c \
	string/ft_strnequ.c \
	string/ft_strnew.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strsplit.c \
	string/ft_strstr.c \
	string/ft_strsub.c \
	string/ft_strtrim.c \
	string/ft_putstr.c \
	string/ft_strcat.c \
	string/ft_strchr.c \
	string/ft_strclr.c \
	string/ft_strcmp.c \
	string/ft_strcpy.c \
	string/ft_strdel.c \
	string/ft_putendl.c \
	string/ft_strrev.c \
	string/ft_strnrev.c \
	ft_pf/ft_arg.c \
	ft_pf/ft_printf.c \
	ft_pf/ft_struct.c \
	ft_pf/print.c \
	ft_pf/char.c \
	ft_pf/ft_flag_for_arg.c \
	ft_pf/int.c \
	ft_pf/percent.c \
	ft_pf/unsigned.c\


OBJ = ft_atoi.o \
	ft_intlen.o \
	ft_charlen.o \
	ft_intlen_base.o \
	ft_itoa_base.o \
	ft_itoa.o \
	ft_putnbr.o \
	ft_strlen.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_putchar.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_lstadd.o \
	ft_lstdel.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memmove.o \
	ft_memset.o \
	ft_bzero.o \
	ft_strdup.o \
	ft_strndup.o \
	ft_strcdup.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	get_next_line.o \
	ft_read_data.o \
	ft_strequ.o \
	ft_strjoinfree.o \
	ft_striter.o \
	ft_strjoin.o \
	ft_strlcat.o\
	ft_strmap.o \
	ft_strmapi.o \
	ft_strncat.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_putstr.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_putendl.o \
	ft_strrev.o \
	ft_strnrev.o \
	ft_pf_itoa.o \
	ft_pf_itoa_base.o \
	ft_chrstr.o \
	ft_putwchar.o \
	ft_intlen_unsigned.o \
	ft_strwlen.o \
	ft_arg.o \
	ft_printf.o \
	ft_struct.o \
	print.o \
	char.o \
	ft_flag_for_arg.o \
	int.o \
	percent.o \
	unsigned.o\

all : $(NAME)

$(NAME) :
		@gcc -Wall -Werror -Wextra -c $(FT)
		@ar rc $(NAME) $(OBJ)
		@rm -rf $(OBJ)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf libft.a

re : fclean all
