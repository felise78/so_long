# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:54:30 by hemottu           #+#    #+#              #
#    Updated: 2023/05/12 21:27:57 by hemottu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
SRC = 	main.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		parsing/parsing.c \
		utils/utils.c \
		utils/ft_split.c \
		parsing/checkers.c \
		parsing/check_path.c \
		events.c \
		render.c \

SRC_BONUS = bonus/main_bonus.c \
			bonus/utils/gnl_bonus.c \
			bonus/utils/gnl_utils_bonus.c \
			bonus/parsing/parsing_bonus.c \
			bonus/utils/utils_bonus.c \
			bonus/utils/ft_split_bonus.c \
			bonus/parsing/check_str_bonus.c \
			bonus/parsing/check_path_bonus.c \
			bonus/events_bonus.c \
			bonus/utils/ft_atoi_bonus.c \
			bonus/utils/ft_itoa_bonus.c \
			bonus/utils/ft_strcat_bonus.c \
			bonus/score_bonus.c \
			bonus/window_bonus.c \
			bonus/load_textures_bonus.c \
			bonus/draw_bonus.c \
			bonus/parsing/get_positions_bonus.c \
			bonus/ghost_bonus.c \
			bonus/free_bonus.c \

OBJ = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

MLX = minilibx-linux/libmlx.a

all: $(NAME) 

bonus: $(NAME_BONUS)

$(MLX): 
	make -C minilibx-linux	

$(NAME): $(OBJ) $(MLX)
	$(CC) $(SRC) $(CFLAGS) -lX11 -lm -lXext -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS) $(MLX)
	rm -rf $(NAME)
	$(CC) $(SRC_BONUS) $(CFLAGS) -lX11 -lm -lXext -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJS_BONUS)
	make clean -C minilibx-linux

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY:	all re clean fclean bonus
