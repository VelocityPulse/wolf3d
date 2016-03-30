# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#*   Updated: 2016/03/15 17:13:25 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =			wolf3d

SRC =			./sources/main.c \
				./sources/start.c \
				./sources/wolf_hook.c \
				./sources/wolf_map.c \
				./sources/wolf3d.c \
				./sources/wolf_dist.c \
				./sources/edit_wolf.c

OBJS =			./main.o \
				./start.o \
				./wolf_hook.o \
				./wolf_map.o \
				./wolf3d.o \
				./wolf_dist.o \
				./edit_wolf.o

DRAW =			./draw/draw.a

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			#-lmlx

FRAMEWORK =		$(LMLX) -framework OpenGL -framework AppKit

FLAGS =			#-Wall -Wextra -Werror -fsanitize=address

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(DRAW) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) $(DRAW) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(DRAW):
	make -C ./draw/

$(LIBMLX):
	make -C ./libmlx/

clean:
	$(RM) $(OBJS)
	make clean -C ./draw/
	make clean -C ./libft/
	make clean -C ./libmlx/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(DRAW) $(LIBMLX)

re: fclean all
