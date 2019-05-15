# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/24 15:30:29 by julee             #+#    #+#              #
#    Updated: 2019/03/24 15:33:46 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGl -framework AppKit

SRC = src/main.c src/draw.c src/board.c src/helper.c

OBJS = $(SRC:.c=.o)

LIBDIR = ../libft

MLXDIR = minilibx_macos

LIB = -L $(LIBDIR) -lft

MLXLIB = -L $(MLXDIR) -lmlx

all: $(NAME)

$(NAME): $(OBJS) libf mlx
	$(CC) $(CFLAGS) $(MLXLIB) $(LIB) $(MLXFLAGS) $(OBJS) -o $(NAME)

libf:
	@$(MAKE) -C $(LIBDIR)

mlx:
	@$(MAKE) -C $(MLXDIR)

.PHONY: clean fclean all re debug

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all
