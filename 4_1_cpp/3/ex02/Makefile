SRCS = ClapTrap.cpp FragTrap.cpp main.cpp
NAME = ClapFrag

all: $(NAME)

$(NAME):
	g++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)