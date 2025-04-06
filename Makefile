##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## task 05 day 5 find square root
##

CC = gcc

SRC =	my_radar_main.c\
		file_to_info.c\
		make_sprites.c\
		move_plane.c\
		check_crash.c\
		free.c

OBJ = $(SRC:.c=.o)

NAME = my_radar

COMP = -lcsfml-graphics  -lcsfml-system  -lcsfml-audio  -lcsfml-window

all: $(NAME)

$(NAME):
	$(CC) -g3 -o $(NAME) $(SRC) $(COMP) -lm

clean:
	rm -f $(OBJ) $(TEST_OBJ)
	rm -f *~
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
