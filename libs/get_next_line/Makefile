# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:05:05 by soopark           #+#    #+#              #
#    Updated: 2022/09/20 14:06:49 by soopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= get_next_line.c get_next_line_utils.c
OBJECT	= $(SRC:.c=.o)
INCS	= .
NAME 	= gnl.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re .c.o bonus