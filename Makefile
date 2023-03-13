# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@stduent.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:58:14 by soopark           #+#    #+#              #
#    Updated: 2023/03/13 15:38:39 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror
MLXFLAG = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit
SRC		= init.c main.c parsing_map.c parsing_rgb.c parsing_texture.c parsing_utils.c parsing.c free.c draw.c draw_util.c move.c raycasting.c
SRC_B := $(addsuffix _bonus.c, $(addprefix srcs_bonus/, $(basename $(SRC)))) srcs_bonus/minimap_rend_bonus.c srcs_bonus/move_bonus.c
SRC		:= $(addprefix srcs/, $(SRC))
OBJECT	= $(SRC:.c=.o)
OBJECT_B = $(SRC_B:.c=.o)
NAME = cub3D
GNL = ./libs/get_next_line
LIBFT = ./libs/libft

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECT)
	make -C $(LIBFT)
	make -C $(GNL)
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(GNL)/gnl.a $(OBJECT) $(MLXFLAG) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJECT)
	rm -f $(OBJECT_B)
	make clean -C $(LIBFT)
	make clean -C $(GNL)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)

bonus : $(OBJECT_B)
	make -C $(LIBFT)
	make -C $(GNL)
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(GNL)/gnl.a $(OBJECT_B) $(MLXFLAG) -o $(NAME)

re : fclean all

.PHONY : all clean fclean re .c.o