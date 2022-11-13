# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 05:19:37 by nloutfi           #+#    #+#              #
#    Updated: 2022/11/13 15:16:46 by nloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 		fdf

SRC =		fdf.c parse.c draw.c tools/ft_atoi.c tools/ft_split.c \
			tools/get_next_line.c tools/get_next_line_utils.c tools/tools0.c \
			tools/tools1.c

OBJ = 		$(SRC:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror -g

FRAMEWORK =	-framework OpenGL -framework AppKit

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ 

all :		$(NAME)

$(NAME) :	$(OBJ)
	make all -C ./mlx
	$(CC) $(FLAGS) $(OBJ) $(FRAMEWORK) ./mlx/libmlx.a -o $(NAME)

clean :
	make clean -C ./mlx
	rm -f $(OBJ) 

fclean :	clean
	rm -f $(NAME)

re :		fclean all