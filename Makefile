# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 14:53:36 by darbib            #+#    #+#              #
#    Updated: 2019/12/10 11:29:27 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

# ------------------------------------------------------------------------------

INC_DIR = includes
HEADERS = $(INC_DIR)/ft_printf.h \
	$(INC_DIR)/ft_sprintf.h  \
	$(INC_DIR)/libft.h 
OBJ = $(SRC:.c=.o)
SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_printf.c \
	ft_sprintf.c \
	buffer.c \
	sbuffer.c \
	conversion.c \
	ident.c \
	utils.c 
PRINTF_DIR = ft_printf


# ------------------------------------------------------------------------------

vpath %.c src
vpath %.c src/$(PRINTF_DIR) 

.PHONY: all clean fclean re

# ------------------------------------------------------------------------------

all : $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o : %.c $(HEADERS)
	$(CC) -I $(INC_DIR) -c $(CFLAGS) $< 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
