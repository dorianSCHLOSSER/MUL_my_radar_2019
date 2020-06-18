##
## EPITECH PROJECT, 2019
## makefile
## File description:
## return
##

SRC =	main.c					\
		my_radar.c				\
		my_all_function.c		\
		my_show.c				\
		my_str_to_word_array.c	\
		my_put_array.c			\
		my_putchar.c			\
		my_getnbr.c				\
		my_parsing.c			\
		my_free_array.c			\
		my_colision.c			\
		my_create_tow_air.c		\
		my_error.c				\
		my_putstr.c

CC = gcc -g

OBJ = $(SRC:.c=.o)

NAME = my_radar

FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all: $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)

re: fclean all
