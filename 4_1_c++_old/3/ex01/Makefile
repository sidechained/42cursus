SRCS = ClapTrap.cpp ScavTrap.cpp main.cpp
NAME = ClapScav	

all: $(NAME)

$(NAME):
	g++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)