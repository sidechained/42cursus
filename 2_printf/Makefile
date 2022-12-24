libftprintf:
	make -C ./libft
	cc -Wall -Wextra -Werror -c ft_printf.c -o ft_printf.o
	cp libft/libft.a libftprintf.a
	ar rc libftprintf.a ft_printf.o

all: libftprintf

clean:
	make -C ./libft clean
	/bin/rm -f ft_printf.o

fclean: clean
	make -C ./libft fclean
	/bin/rm -f libftprintf.a

re: fclean all

test:
	cc tests.c libftprintf.a
	./a.out