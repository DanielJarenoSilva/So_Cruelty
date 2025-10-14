NAME = so_long

LIBFT_DIR = ./libraries/libft
MLX_DIR = ./libraries/MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/include -I$(MLX_DIR)/include -I. -g3
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)/build -lmlx42 -lglfw -ldl -lm -lX11 -lpthread

CC = cc

SRCS = src/main.c \
		src/so_long.c \
       	src/parse_map.c \
		src/so_long_utils.c \
		src/move.c \
		src/textures.c \

OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
