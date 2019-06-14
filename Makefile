NAME := libftprintf.a
NAME_1 := ft_printf
NAME_2 := printf
SRC =   src/common_tool.c \
		src/common_tool2.c \
		src/ft_itoa_base_unsigned.c \
		src/ft_itoa_base.c \
		src/ft_printf.c \
		src/integer_conversion.c \
		src/parsing.c \
		src/unsigned_conversion.c \
		src/flag_hub.c \
		src/convert_parse.c \
		src/char_conversion.c \
		src/string_conversion.c \
		src/p_conversion.c \
		src/f_conversion_tools.c \
		src/mult_str.c \
		src/tools_join.c \
		src/ft_atoi.c \
		src/ft_memmove.c \
		src/ft_strrevcpy.c \
		src/ft_strcpy.c \
		src/ft_strdel.c \
		src/ft_strdup.c \
		src/ft_strlen.c \
		src/ft_strndup.c \
		src/ft_strnew.c \
		src/ft_strsub.c \
		src/tool.c \
		src/print.c \
		src/percent_conversion.c

OBJ := $(SRC:.c=.o)
FLAGS := -Wall -Wextra -Werror
HDIR := include

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

%.o: %.c
	gcc -I $(HDIR) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

