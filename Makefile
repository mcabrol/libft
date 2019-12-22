# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 11:25:08 by mcabrol           #+#    #+#              #
#    Updated: 2019/11/08 19:01:51 by mcabrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INC = -Iinc

SRC = \
string/ft_memset.c	string/ft_strcmp.c	list/ft_striter.c \
string/ft_bzero.c	string/ft_strncmp.c	list/ft_striteri.c \
string/ft_memcpy.c	string/ft_strnew.c	list/ft_strmap.c \
string/ft_memmove.c	string/ft_strclr.c	list/ft_strmapi.c \
string/ft_memchr.c	string/ft_strequ.c	list/ft_lstnew.c \
string/ft_memcmp.c	string/ft_strnequ.c	list/ft_lstdel.c \
string/ft_memdel.c	string/ft_strsub.c	list/ft_lstdelone.c \
string/ft_memccpy.c	string/ft_strjoin.c	list/ft_lstadd.c \
string/ft_memalloc.c	string/ft_strtrim.c	stdio/ft_putchar.c \
string/ft_strlen.c	string/ft_strsplit.c	stdio/ft_putstr.c \
string/ft_strdup.c	string/ft_strdel.c	stdio/ft_putendl.c \
string/ft_strcpy.c	stdlib/ft_itoa.c	stdio/ft_putnbr.c \
string/ft_strncpy.c	stdlib/ft_atoi.c	stdio/ft_putchar_fd.c \
string/ft_strcat.c	ctype/ft_toupper.c	stdio/ft_putstr_fd.c \
string/ft_strncat.c	ctype/ft_tolower.c	stdio/ft_putnbr_fd.c \
string/ft_strlcat.c	ctype/ft_isdigit.c	stdio/ft_putendl_fd.c \
string/ft_strchr.c	ctype/ft_isalpha.c	stdio/ft_putendl_fd.c \
string/ft_strrchr.c	ctype/ft_isalnum.c	gnl/get_next_line.c \
string/ft_strstr.c	ctype/ft_isascii.c \
string/ft_strnstr.c	ctype/ft_isprint.c \

COMPILE.c = $(CC) $(CFLAGS) $(INC) $(TARGET_ARCH) -c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	@ar -rc $(NAME) $?

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
