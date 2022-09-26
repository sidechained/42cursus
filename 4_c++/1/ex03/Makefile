SRCS = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
NAME = UnnecessaryViolence.out

all: UnnecessaryViolence

UnnecessaryViolence:
	g++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

run: UnnecessaryViolence
	./$(NAME)

clean:
	rm -f $(NAME)