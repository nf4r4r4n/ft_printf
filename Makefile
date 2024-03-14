NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
SRC=ft_printf.c ft_printf_utils.c
OBJS=${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $@ $?

%.o: %.c
	cc $(CFLAGS) -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
