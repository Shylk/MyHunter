##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	set_values.c			\
		main.c				\
		move.c				\
		my_int_to_str.c			\
		my_revstr.c			\
		refresh_and_destroy.c		\
		click_gestion.c			\
		my_putstr.c			\
		my_putchar.c			\
		text.c				\
		texture_sprite.c		\
		game_over.c			\
		game_over_2.c			\
		menu.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Iinclude -L lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
