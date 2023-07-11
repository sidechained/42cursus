SRCS = DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp
NAME = DiamondTrap

all: $(NAME)

$(NAME):
	g++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)