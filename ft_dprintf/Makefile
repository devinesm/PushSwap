NAME	= libftdprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_dprintf.c handlers_1.c handlers_2.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
