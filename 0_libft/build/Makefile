# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grm <grm@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 23:29:41 by grm               #+#    #+#              #
#    Updated: 2022/11/23 23:24:35 by grm              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ../inc/libft.h
FLAGS = -Wall -Wextra -Werror
FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd 
SRCS = $(addprefix ../src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ../build/, $(addsuffix .o, $(FILES)))

$(NAME):
	gcc $(FLAGS) -include $(HEADER) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all