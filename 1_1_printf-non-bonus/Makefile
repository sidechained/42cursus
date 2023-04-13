NAME = libftprintf.a

$(NAME):
	make -C ./libft
	cc -Wall -Wextra -Werror -c ft_printf.c ft_printf_conversions.c ft_printf_utils.c ft_printf_uitoa.c 
	cp libft/libft.a $(NAME)
	ar rc $(NAME) ft_printf.o ft_printf_conversions.o ft_printf_utils.o ft_printf_uitoa.o

# mandatory:
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
	cc ../1_2_printf-tests/tests.c $(NAME) -o tests
	valgrind ./tests
	rm tests

# bonuses:
bonus:
	make -C ./libft
	cc -Wall -Wextra -Werror -c ft_printf_bonus.c ft_printf_bonus_conversions.c ft_printf_bonus_flags1.c ft_printf_bonus_flags2.c ft_printf_bonus_utils.c ft_printf_bonus_uitoa.c
	cp libft/libft.a $(NAME)
	ar rc $(NAME) ft_printf_bonus.o ft_printf_bonus_conversions.o ft_printf_bonus_flags1.o ft_printf_bonus_flags2.o ft_printf_bonus_utils.o ft_printf_bonus_uitoa.o

clean-bonus:
	make -C ./libft clean
	rm -f ft_printf_bonus.o ft_printf_bonus_conversions.o ft_printf_bonus_flags1.o ft_printf_bonus_flags2.o ft_printf_bonus_utils.o ft_printf_bonus_uitoa.o

fclean-bonus: clean-bonus
	make -C ./libft fclean
	rm -f $(NAME)

re-bonus: fclean-bonus bonus

test-bonus:
	make fclean-bonus
	make bonus
	clear
	cc -Wall -Werror -Wextra -ggdb3 ../1_1_printf-tests/failed-bonus-tests.c $(NAME) -o bonus-tests
# 	valgrind --leak-check=full ./bonus-tests
	./bonus-tests
# 	rm bonus-tests

.PHONY: all clean fclean re test bonus clean-bonus fclean-bonus re-bonus test-bonus