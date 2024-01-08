# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahtuncay <ahtuncay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 17:08:43 by ahtuncay          #+#    #+#              #
#    Updated: 2023/12/30 15:21:40 by ahtuncay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# ----- LIBRARY ----- #
HEADER  = so_long.h
MLX_LIB = $(MLX_PATH)/libmlx.a

# ----- PATH ----- #
MLX_PATH = ./minilibx
INC_PATH = -I$(MLX_PATH) -I$(HEADER)

# ----- SOURCE & OBJECT FILES ----- #
SRC  =  main.c \
		input.c \
		utils.c \
		start_game.c \
		press_image.c \
		map_control.c \
		map_validation.c \
		movement_control.c  
OBJ = $(SRC:.c=.o)

# ----- COMPILING VARIABLES ----- #
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# ----- COLORS ----- #
GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
CYAN    = \033[36;1m
MAGENTA = \033[0;35m
RESET   = \033[0m

all: $(NAME)

.c.o:
	@ ${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	@ echo "\n\t\t🟡$(YELLOW) Compilation of $(NAME) ... $(RESET)"

	@ $(MAKE) -sC $(MLX_PATH) >/dev/null 2>&1
	@ echo "\n"

	@ $(CC) -o $(NAME) $(OBJ) $(MLX_FLAGS)
	@ echo "\n🟢$(GREEN) The project has been compiled,	❗️$(RED) Are You Readyy?!?!?!? $(RESET)\n"

norm:
	@ echo "\n"
	@ norminette $(SRC) $(HEADER) 2>/dev/null; \
	if [ $$? -eq 0 ]; then \
		echo "\n🟢$(GREEN) Norminette check passed!$(RESET)\n"; \
	else \
		echo "\n🔴$(RED) Norminette check failed!$(RESET)\n"; \
	fi

clean:
	@ $(MAKE) -sC $(MLX_PATH) clean
	@ rm -rf *.o
	@ echo "\n	🗑️$(MAGENTA)  Delete : objects $(RESET)\n"

fclean: clean
	@ rm -f $(MLX_LIB)
	@ echo "	🗑️$(MAGENTA)  Delete : $(MLX_LIB) $(RESET)"
	@ rm -f $(NAME)
	@ echo "\n	🗑️$(MAGENTA)  Delete : $(NAME) $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
