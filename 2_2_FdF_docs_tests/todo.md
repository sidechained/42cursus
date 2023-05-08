what happens if we get rid of s_point typedefs? does norminette complain?

TODO: push
TODO: fix mixed up double error messages
TODO: fix segfault on exit (esc or window close)
TODO: leak check
TODO: implement colours
TODO: set limits on paramaters (max zoom, max outside bounds, max scaling etc)
TODO: arguments 3 and 4 = window size

clear; cc -Wall -Werror -Wextra fdf-new2.c get_next_line/get_next_line.c libft/ft_isdigit.c libft/ft_strlen.c libft/ft_substr.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_atoi.c -Iget_next_line -Ilibft -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz && ./a.out test_maps/3x3.fdf