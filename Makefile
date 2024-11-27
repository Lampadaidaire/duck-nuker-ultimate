##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

CC = gcc

NAME	=	my_hunter

SRC	=	src/main.c 	\
		src/analyse_events.c	\
		src/universel_creator.c	\
		src/random.c	\
		src/image_creator.c	\
		src/destroyer.c	\
		src/image_creator2.c	\
		src/display_new_lvl.c	\
		src/handle_end_game.c	\
		src/create_duck.c	\
		src/handle_pause_menu.c	\
		src/nuke.c	\
		src/game.c	\
		src/handle_cursor.c	\
		src/menu.c	\
		src/handle_duck_death.c	\
		src/handle_ducks.c	\

OBJ	=	$(SRC:.c=.o)

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS	= -Iinclude -Wextra -Wall -Wshadow
LDFLAGS =	-lmy -Llib/my/ $(CSFML)

all:	$(NAME)

lib/my/libmy.a:
		make -C lib/my/


$(NAME):	$(OBJ) lib/my/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make clean -C lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean	all
