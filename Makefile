CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm


NAME = so_long.exe

SRCS = checks.c end_game.c free_images_1.c ft_moves_2.c ft_moves.c images_1.c images_2.c king_animations.c main.c so_long.c utils_2.c utils_3.c utils.c animations.c utils_4.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@make all -C $(MLX_DIR)
	@$(CC) -fPIE $(CFLAGS) $(SRCS) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@clear
	@echo "\nLet's play !!\n"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@rm -f $(NAME)

re: fclean all

replay:
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@clear
	@echo "\nLet's play !!\n"

.PHONY: all clean fclean re replay
