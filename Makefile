# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soopark <soopark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:58:14 by soopark           #+#    #+#              #
#    Updated: 2023/03/09 15:30:52 by soopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address
MLXFLAG = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit
SRC		= init.c main.c parsing_map.c parsing_rgb.c parsing_texture.c parsing_utils.c parsing.c free.c draw.c draw_util.c
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
	make clean -C $(LIBFT)
	make clean -C $(GNL)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)

re : fclean all

.PHONY : all clean fclean re .c.o