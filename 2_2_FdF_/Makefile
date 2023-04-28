OBJ_DIR := obj
HDR_DIR := inc
SRC_DIR := src

LIBFT_DIR := libft
NAME := push_swap
SRC := $(wildcard $(LIBFT_DIR)/*.c)
SRC += $(SRC_DIR)/init.c
SRC += $(SRC_DIR)/conversion_values_indices.c
SRC += $(SRC_DIR)/input_error_checking.c
SRC += $(SRC_DIR)/operations_push.c
SRC += $(SRC_DIR)/operations_push_all.c
SRC += $(SRC_DIR)/operations_swap.c
SRC += $(SRC_DIR)/operations_rotate.c
SRC += $(SRC_DIR)/operations_rotate_reverse.c
SRC += $(SRC_DIR)/print_stacks.c
SRC += $(SRC_DIR)/sort.c
SRC += $(SRC_DIR)/utils.c
PUSH_SRC += $(SRC_DIR)/push_swap.c
CHKR_SRC += $(SRC_DIR)/checker.c
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
PUSH_OBJ := $(PUSH_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHKR_OBJ := $(CHKR_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ${PUSH_OBJ} ${OBJ}
	@make -C ./libft
	@cc -I$(HDR_DIR) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@cc -I$(HDR_DIR) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

bonus: checker

checker: ${CHKR_OBJ} ${OBJ}
	@make -C ./libft
	@cc -I$(HDR_DIR) $(CFLAGS) $^ -o $@	

clean:
	@make -C ./libft clean
	@rm -f $(OBJ_DIR)/*

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@rm -f checker	

re: fclean all

re-bonus: fclean bonus

.PHONY: all clean fclean re 