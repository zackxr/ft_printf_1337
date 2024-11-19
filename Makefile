NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_printmem.c ft_printhex.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean ar