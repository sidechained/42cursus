NAME = libft.a
SRC_PATH = ./srcs/
HEADER_PATH = ./incs/
BUILD_PATH = ./build/
FLAGS = 
SRCS = $(SRC_PATH)ft_printf.c
SRCS+ = $(SRC_PATH)conversions_others.c
SRCS+ = $(SRC_PATH)conversions_strings.c
SRCS+ = $(SRC_PATH)paddings.c
SRCS+ = $(SRC_PATH)puts.c
SRCS+ = $(SRC_PATH)puts_base.c
OBJS = $(BUILD_PATH)conversions_others.o
OBJS++ = $(BUILD_PATH)conversions_strings.o
OBJS++ = $(BUILD_PATH)paddings.o
OBJS++ = $(BUILD_PATH)puts.o
OBJS++ = $(BUILD_PATH)puts_base.o

$(NAME):
	cc -Wall -Wextra -Werror -I $(HEADER_PATH) -c $(SRCS) -o $(OBJS)
	ar rc $(NAME) $(OBJS)

all:
	$(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all