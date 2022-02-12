NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

SRCS = ft_printf.c ft_putnbr.c ft_putstr.c ft_putchar.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
	gcc $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

