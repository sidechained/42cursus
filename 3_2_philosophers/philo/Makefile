OBJ_DIR := obj
HDR_DIR := inc
LFT_DIR := libft
SRC_DIR := src

NAME := philo
SRC += $(SRC_DIR)/philo.c
SRC += $(SRC_DIR)/threads.c
SRC += $(SRC_DIR)/utils.c
SRC += $(LFT_DIR)/*.c
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ${OBJ}
	@cc -I$(HDR_DIR) -I$(LFT_DIR) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@cc -I$(HDR_DIR) -I$(LFT_DIR) -I$(HDR_DIR) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -f $(OBJ_DIR)/*

fclean: clean
	@rm -f $(NAME)
	@rm -f checker	

re: fclean all

.PHONY: all clean fclean re 