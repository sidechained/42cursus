NAME			= diamondtrap
SRCS			= DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp main.cpp
OBJS			= $(SRCS:.cpp=.o)
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -Wno-shadow -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re