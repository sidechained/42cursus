NAME = libftprintf.a
HEADER = libftprintf.h
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c puts.c puts_base.c paddings.c conversions_others.c conversions_strings.c
OBJS = $(SRCS:.c=.o)


$(NAME):
	cc $(FLAGS) -include $(HEADER) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all:
	$(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	rm tests

re: fclean all

test:
	cc -o tests tests.c libftprintf.a
	./tests

# cc -o tests tests.c libftprintf.a