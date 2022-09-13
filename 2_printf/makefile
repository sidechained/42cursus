NAME = libft.a
SRC_PATH = ./srcs/
HEADER_PATH = ./incs/
FLAGS = -Wall -Wextra -Werror
SRCS = $(SRC_PATH)ft_printf.c
SRCS+ = $(SRC_PATH)conversions_others.c
SRCS+ = $(SRC_PATH)conversions_strings.c
SRCS+ = $(SRC_PATH)paddings.c
SRCS+ = $(SRC_PATH)puts.c
SRCS+ = $(SRC_PATH)puts_base.c
OBJS = conversions_others.o conversions_strings.o paddings.o puts.o puts_base.o

build:
	gcc $(FLAGS) -I $(HEADER_PATH) -c $(SRCS)

makelib:
	ar rc $(NAME) $(OBJS)

$(NAME):
	build
	makelib
	
all:
	$(NAME)

clean:
	/bin/rm -f $(OBJS)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
