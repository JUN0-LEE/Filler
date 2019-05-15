# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 08:52:25 by julee             #+#    #+#              #
#    Updated: 2019/04/20 16:14:58 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./resources/players/julee.filler

CC = @gcc -Wall -Wextra -Werror

SRC = ./src/main.c ./src/board.c ./src/piece.c ./src/initializer.c \
./src/heatmap.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

VIS = ./visualizer/visualizer

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(VIS)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
	@cd libft && make

$(VIS):
	@cd visualizer && make

clean:
	@rm -f $(OBJ)
	@cd libft && make clean
	@cd visualizer && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd visualizer && make fclean

re: fclean all
