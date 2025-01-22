# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2025/01/21 01:24:53 by asiatik           #+#    #+#              #
# #    Updated: 2025/01/22 14:59:26 by asiatik          ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

# # # Nom du programme
# # NAME = fdf

# # # Répertoires
# # SRC_DIR = sources
# # INC_DIR = includes
# # OBJ_DIR = objets

# # #libft
# # LIBFTDIR = libft
# # LIBFT = $(LIBFTDIR)/libft.a

# # #minilibx
# # MINILIBXTAR = minilibx-linux.tgz
# # MINILIBXDIR = ./minilibx-linux
# # MINILIBX = $(MINILIBXDIR)/libmlx.a

# # # Fichiers sources
# # SRC = $(shell find $(SRC_DIR) -name "*.c")
# # OBJ = $(SRC:.c=.o)
# # SRC := $(addprefix $(SRC_DIR)/, $(SRC))
# # OBJ := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(OBJ))

# # # Flags de compilation
# # CC = gcc
# # CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -g3 -I$(MINILIBXDIR) -I/usr/include/X11 -I$(LIBFTDIR)

# # # Colors
# # RED     := "\033[1;31m"
# # GREEN   := "\033[1;32m"
# # RESET   := "\033[0m"

# # # Compilation mode (silent by default, set VERBOSE=1 to show commands)
# # VERBOSE ?= 0
# # ifeq ($(VERBOSE),1)
# #   V := 
# # else
# #   V := @
# # endif

# # # Flags pour MiniLibX
# # MLX_FLAGS = -L$(MINILIBXDIR) -lmlx -lm -lXext -lX11

# # # Règles principales
# # all: $(OBJ_DIR) $(MINILIBXDIR) $(LIBFT) $(NAME)

# # # Object Directory Rule
# # $(OBJ_DIR):
# # 	$(V)mkdir -p $(OBJ_DIR) || true

# # # Dependency Files
# # DEP = $(OBJ:.o=.d)

# # $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
# # 	@mkdir -p $(dir $@)
# # 	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# # -include $(DEP)

# # # Linking Rule
# # $(NAME): $(OBJ) 
# # 	@make -C ./libft
# # 	@cp $(LIBFT) $(NAME) 
# # 	@ar rcs $@ $(OBJS)
# # 	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
# # 	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)

# # # Libft
# # $(LIBFT):
# # 	$(V)make --silent -C $(LIBFTDIR)
# # 	$(V)echo '[$(NAME)] Libft build successfully'
	
# # $(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
# # 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# # # Compilation de MiniLibX
# # $(MINILIBXDIR):
# # 	$(V)echo '[$(NAME)] Decompressed MiniLibX...'$(RESET)
# # 	@tar -xzvf $(MINILIBXTAR)
# # 	$(V)echo '[$(NAME)] Compiling MiniLibX...'$(RESET)
# # 	@make -C $(MINILIBXDIR)
# # 	$(V)echo '[$(NAME)] MiniLibX installed successfully'$(RESET)

# # # Nettoyage
# # clean:
# # 	@rm -rf $(OBJ)
# # 	@make clean -C $(LIBFTDIR)
# # 	@if [ -d $(MINILIBXDIR) ]; then make clean -C $(MINILIBXDIR); fi
# # 	@echo "Nettoyage des fichiers objects!"

# # fclean: clean
# # 	@rm -rf $(NAME)
# # 	@make fclean -C $(LIBFTDIR)
# # 	@rm -rf $(MINILIBXDIR)
# # 	@echo "Netoyage complet!"

# # re: fclean all

# # .PHONY: all clean fclean re

# # Nom du programme
# NAME = fdf

# # Répertoires
# SRC_DIR = sources
# INC_DIR = includes
# LIBFT_DIR = libft
# MLX_TAR = minilibx-linux.tgz
# MLX_DIR = minilibx-linux

# # Fichiers sources
# SRC = $(shell find $(SRC_DIR) -name "*.c")
# OBJ = $(SRC:.c=.o)

# # Flags de compilation
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

# # Flags pour MiniLibX
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

# # Règles principales
# all: $(NAME)

# $(NAME): $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -o $(NAME)

# # Compilation des fichiers objets
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Compilation de Libft
# $(LIBFT_DIR)/libft.a:
# 	@make -C $(LIBFT_DIR)

# # Compilation de MiniLibX
# $(MLX_DIR)/libmlx.a:
# 	@make -C $(MLX_DIR)
# 	@echo "MiniLibX installed successfully!"
	

# # Nettoyage
# clean:
# 	@rm -f $(OBJ)
# 	@make clean -C $(LIBFT_DIR)
# 	@if [ -d $(MLX_DIR) ]; then make clean -C $(MLX_DIR); fi
# 	@echo "Nettoyage des fichiers objects!"

# fclean: clean
# 	@rm -f $(NAME)
# 	@make fclean -C $(LIBFT_DIR)
# 	@rm -rf ./minilibx-linux
# 	@echo "Netoyage complet!"

# re: fclean all

# # Règle pour décompresser MiniLibX (optionnel)
# setup_mlx:
# 	@tar -xvzf minilibx-linux.tgz

# .PHONY: all clean fclean re setup_mlx

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