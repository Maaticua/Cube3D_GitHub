NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR		= srcs
OBJ_DIR		= obj
INC_DIR		= include
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# **************************************************************************** #
#                                 SOURCE FILES                                 #
# **************************************************************************** #

SRC_FILES	= main.c \

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# **************************************************************************** #
#                                  LIBRARIES                                   #
# **************************************************************************** #

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# **************************************************************************** #
#                                   INCLUDES                                   #
# **************************************************************************** #

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(GREEN)Compiling miniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
