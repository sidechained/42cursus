NAME = libftprintf.a

$(NAME):
	make -C ./libft
	cc -Wall -Wextra -Werror -c ft_printf.c ft_printf_conversions.c ft_printf_utils.c ft_uitoa.c 
	cp libft/libft.a $(NAME)
	ar rc libftprintf.a ft_printf.o ft_printf_conversions.o ft_printf_utils.o ft_uitoa.o

all: $(NAME)

clean:
	make -C ./libft clean
	rm -f ft_printf.o ft_printf_conversions.o ft_printf_utils.o ft_uitoa.o

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

test:
	make all
	clear
	cc ../2_printf-tests/tests.c $(NAME) -o tests
	./tests
	rm tests 