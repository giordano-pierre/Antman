##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-nathan.baudelin
## File description:
## Makefile
##

NAME	=	giantman

SRC =	main.c	\
		recup_file.c	\
		giantman.c \
		fonctions_utiles.c	\
		make_free.c	\
		create_leaf.c	\
		create_tree.c	\
		sort.c	\
		bin.c	\

RM = rm -Rf

CFLAGS = -g3 -Wall -Wextra

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all, clean, fclean, re
