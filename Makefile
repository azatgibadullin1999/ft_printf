NAME = libftprintf.a

MAIN_C =	ft_printf.c\
			ft_parser.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_isdigit.c\
			ft_itoa.c\
			ft_memcpy.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_toupper.c\
			ft_percent_output.c\
			ft_char_types_output.c\
			ft_str_types_output.c\
			ft_hex_types_output.c\
			ft_int_types_output.c\
			ft_pointer_types_output.c\
			ft_unsigned_types_output.c

MAIN_O = $(MAIN_C:.c=.o)

CC = gcc

HEAD = -I ./ft_printf.h

all: $(MAIN_O) $(NAME)

$(NAME):
	ar rc $(NAME) $(MAIN_O)
	ranlib $(NAME)

%.o : %.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean: 
	rm -f $(MAIN_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all lib clean fclean re %.o
