NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra


SOURCES = ft_strlen.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_base.c \
		ft_printf.c

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^

%.o:%.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : fclean all