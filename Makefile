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

OUT =				MAC
#OUT =				LINUX

COMPILE_SDL =		YES
#COMPILE_SDL =		NO

NAME =				wolf3d

SRC =				./sources/main.c \
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

OBJS =				./main.o \
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

LIBFT =				./libft/libft.a

PATHSDL =			./SDL2-2.0.4

PATHFRAMEWORKSDL =	./SDL.framework

EXTRAFLAGS =		-fsanitize=address -Wall -Wextra -Werror

CC =				gcc

RM =				rm -f

ifeq ($(OUT),MAC)

ifeq ($(COMPILE_SDL),YES)
DYNLIB =			libSDL2-2.0.0.dylib
PATHDYNLIB =		./$(PATHSDL)/build/.libs/$(DYNLIB)
LFLAGS =			-L$(PATHSDL)/build/.libs -lSDL2
EDITLIB =			install_name_tool -change /usr/local/lib/$(DYNLIB) @executable_path/$(PATHDYNLIB) $(NAME)

else
LFLAGS =			-L$(PATHFRAMEWORKSDL)/Versions/Current -F. -framework SDL2 -framwork Cocoa
EDITLIB =			install_name_tool -change @rpath/SDL2.framework/Version/A/SDL2 @executable_path/SDL2.framework/SDL2 $(NAME) && install_name_tool -change @executable_path/../Frameworks/$(PATHFRAMEWORKSDL)/SDL2 @executable_path/$(PATHFRAMEWORKSDL)/SDL2

endif

else
PATHDYNLIB =		./$(PATHSDL)/build/.libs/libSDL2-2.0.so.0
SPECIFYLIB =		-Wl, -R`pwd`/$(PATHSDL)/build/.libs
LFLAGS =			$(SPECIFYLIB) -L$(PATHSDL)/build/.libs -lSDL2

endif

all: $(NAME)

ifeq ($(OUT),MAC)

ifeq ($(COMPILE_SDL),YES)
$(NAME): $(PATHDYNLIB) $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

$(PATHDYNLIB):
	./$(PATHSDL)/configure
	make -C ./$(PATHSDL)

else
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

endif

else
$(NAME): $(PATHDYNLIB) $(LIBFT) $(OBJS)
	$(CC) $(EXTRAFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

$(PATHDYNLIB): #xorg-dev installed
	./$(PATHSDL)/configure
	make -C ./$(PATHSDL)

endif

$(OBJS): $(LIBFT)
	$(CC) $(EXTRAFLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/

fclean: clean
	make clean -C ./$(PATHSDL)
	rm -Rf ./$(PATHSDL)/build
	$(RM) $(NAME) $(LIBFT)

re: fclean all
