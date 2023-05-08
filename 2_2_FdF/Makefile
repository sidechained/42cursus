NAME := fdf
OBJ_DIR := obj
HDR_DIR := inc
SRC_DIR := src
LFT_DIR := libft
GNL_DIR := get_next_line
SRC := $(LFT_DIR)/ft_strlen.c
SRC += $(LFT_DIR)/ft_substr.c
SRC += $(LFT_DIR)/ft_strjoin.c
SRC += $(LFT_DIR)/ft_strdup.c
SRC += $(LFT_DIR)/ft_split.c
SRC += $(LFT_DIR)/ft_atoi.c
SRC += $(LFT_DIR)/ft_isdigit.c
SRC += $(GNL_DIR)/get_next_line.c
SRC += $(SRC_DIR)/fdf.c
SRC += $(SRC_DIR)/fdf_draw_1.c
SRC += $(SRC_DIR)/fdf_draw_2.c
SRC += $(SRC_DIR)/fdf_projections.c
SRC += $(SRC_DIR)/fdf_read.c
SRC += $(SRC_DIR)/fdf_keyloop.c
SRC += $(SRC_DIR)/fdf_transformations.c
SRC += $(SRC_DIR)/fdf_utils.c

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCS := -I$(LFT_DIR) -I$(GNL_DIR) -I$(HDR_DIR)
CFLAGS := -Wall -Werror -Wextra
LIBS := -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): ${OBJ}
	@make -C ./libft
	cc $(CFLAGS) $(INCS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@cc $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ_DIR)/*

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re