# **************************************************************************** #
#                                   CUB3D                                      #
# **************************************************************************** #

# Standard
NAME				= cub3D

# Directories
LIBFT				= ./libft/libft.a
MLX					= ./minilibx-linux/libmlx.a
INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g -I
MLX_FLAGS			= -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz
RM					= rm -f

# Concatenate all source files
SRCS				=	$(SRC_DIR)main.c							\
						$(SRC_DIR)mlx/mlx_utils.c					\
						$(SRC_DIR)mlx/render.c						\
						$(SRC_DIR)mlx/game_utils.c					\
						$(SRC_DIR)mlx/ray_casting.c					\
						$(SRC_DIR)parsing/parse_elements.c			\
						$(SRC_DIR)parsing/parse_file.c				\
						$(SRC_DIR)parsing/parse_identifiers.c		\
						$(SRC_DIR)parsing/parse_map.c				\
						$(SRC_DIR)parsing/parse_utils.c				\
						$(SRC_DIR)parsing/validate_file.c			\
						$(SRC_DIR)parsing/validate_map.c			\
						$(SRC_DIR)parsing/validate_texture.c		\
						$(SRC_DIR)utils/error.c						\

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ					= $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRCS))

# Build rules
start:
					@make all

$(LIBFT):
					@make -C ./libft

$(MLX):
					@make -C ./minilibx-linux

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT) $(MLX)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
					@echo "✅ $(NAME) compiled successfully!"

# Compile object files from source files
$(OBJ_DIR)/%.o:		%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@
					@echo "Compiling $<"

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@make clean -C ./minilibx-linux
					@echo "🧹 Object files cleaned!"

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "🗑️  Executable removed!"

re:					fclean all

# Phony targets represent actions not files
.PHONY:				start all clean fclean re
