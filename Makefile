# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#*   Updated: 2016/04/22 12:29:28 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =			wolf3d

SRC =			./sources/main.c \
				./sources/start.c \
				./sources/wolf_hook.c \
				./sources/wolf_map.c \
				./sources/wolf3d.c \
				./sources/edit_wolf.c \
				./sources/reset_image.c \
				./sources/delta_time.c \
				./sources/get_next_line.c \
				./sources/wolf_get_path.c \
				./sources/exit_wolf.c \
				./sources/wolf_check_map.c \
				./sources/error_text.c \
				./sources/wolf_complete_case.c \
				./sources/display_map.c \
				./sources/load_texture.c \
				./sources/clear_texture.c \
				./sources/trace.c \
				./sources/trace_monocolor.c

OBJS =			./main.o \
				./start.o \
				./wolf_hook.o \
				./wolf_map.o \
				./wolf3d.o \
				./edit_wolf.o \
				./reset_image.o \
				./delta_time.o \
				./get_next_line.o \
				./wolf_get_path.o \
				./exit_wolf.o \
				./wolf_check_map.o \
				./error_text.o \
				./wolf_complete_case.o \
				./display_map.o \
				./load_texture.o \
				./clear_texture.o \
				./trace.o \
				./trace_monocolor.o

DRAW =			./draw/draw.a

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			#-lmlx

FRAMEWORK =		$(LMLX) -framework OpenGL -framework AppKit -o3

FLAGS =			-fsanitize=address -Wall -Wextra -Werror

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
