CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
OBJ_DIR = obj
SRC_DIR = .
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I$(SRC_DIR)
SRC_FILES =	$(SRC_DIR)/ft_add_prefix.c \
			$(SRC_DIR)/ft_add_sign.c \
			$(SRC_DIR)/ft_add_space.c \
			$(SRC_DIR)/ft_add_width.c \
			$(SRC_DIR)/ft_add_zeros.c \
			$(SRC_DIR)/ft_align_left.c \
			$(SRC_DIR)/ft_basic_output.c \
			$(SRC_DIR)/ft_itoa_base.c \
			$(SRC_DIR)/ft_modify_arg.c \
			$(SRC_DIR)/ft_precision.c \
			$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_print_pointer.c \
			$(SRC_DIR)/ft_utils.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_FILES)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_FILES)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re libft
