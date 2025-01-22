# Nom du programme
NAME = fdf

# Répertoires
SRC_DIR = sources
INC_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
#PRINTF_DIR = ft_printf
#PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_TAR = minilibx-linux.tgz
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# Fichiers sources
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS	:= $(SRCS:%.c=%.o)

# Flags de compilation
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) #-I$(PRINTF_DIR)

RM		= rm -rf
# Colors
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

# Flags pour MiniLibX
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

all:	$(MLX) $(LIBFT) $(NAME) #$(PRINTF_DIR)

# Compilation des fichiers objets
%.o:	%.c
		$(CC) $(CFLAGS) -c $? -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX) #$(PRINTF)
#	@make -C ft_printf
	@make -C libft
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME) #$(PRINTF)
	@echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

# Compilation de Libft
$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo '[$(NAME)] Libft build successfully'

#compilation de printf
# $(PRINTF):
# 	@make -C $(PRINTF_DIR)

# Compilation de MiniLibX
$(MLX):
	@echo '[$(NAME)] Downloading MiniLibX ...'$(RESET)
	@tar -xvzf $(MLX_TAR)
	@make -C $(MLX_DIR)
	@echo '[$(NAME)] MiniLibX installed successfully'$(RESET)

#Nettoyage
clean:
	@make clean -C $(LIBFT_DIR)
#	@make clean -C $(PRINTF_DIR)
	@if [ -d $(MLX_DIR) ]; then make clean -C $(MLX_DIR); fi
	@${RM} ${OBJS}
	@echo "Nettoyage des fichiers objects! ✅"

fclean:		clean
	@echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	@${RM} ${NAME}
	@make -C $(LIBFT_DIR) fclean
#	@make -C $(PRINTF_DIR) fclean
	@echo $(RED)'[mlx] Remove directory'$(RESET)
	@rm -rf ./minilibx-linux
	@echo $(GREEN)"NETTOYAGE COMPLET ✅!"

# Règle pour décompresser MiniLibX
setup_mlx:
	@tar -xvzf minilibx-linux.tgz

re:		fclean all

.PHONY:	all clean fclean re setup_mlx