##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##
CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	my_runner

SRCS	=	srcs/runner/main.c \
		srcs/lists/create_list.c \
		srcs/lists/display_list.c \
		srcs/runner/entity/collision.c \
		srcs/runner/entity/create.c \
		srcs/runner/entity/display.c \
		srcs/runner/entity/get_obj.c \
		srcs/runner/entity/move.c \
		srcs/runner/entity/text.c \
		srcs/runner/game/clean_up.c \
		srcs/runner/game/create_my_window.c \
		srcs/runner/game/error.c \
		srcs/runner/game/end_game.c \
		srcs/runner/game/event.c \
		srcs/runner/game/check_event.c \
		srcs/runner/game/check_mouse.c \
		srcs/runner/game/map.c \
		srcs/runner/game/my_runner.c \
		srcs/runner/init/init_defeat_screen.c \
		srcs/runner/init/init_game.c \
		srcs/runner/init/init_help_screen.c \
		srcs/runner/init/init_intro_screen.c \
		srcs/runner/init/init_menu.c \
		srcs/runner/init/init_sound.c \
		srcs/runner/init/init_sprite.c \
		srcs/runner/init/init_victory_screen.c \
		srcs/runner/math/math.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re