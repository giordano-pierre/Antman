##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-nathan.baudelin
## File description:
## Makefile
##

RM = rm -Rf

ANTMAN_CREATE = cd antman && make && cd ../

GIANTMAN_CREATE = cd giantman && make && cd ../

all:
	$(ANTMAN_CREATE)
	$(GIANTMAN_CREATE)

clean:
	$(RM) antman/antman
	$(RM) giantman/giantman

fclean:	clean
	$(RM) antman/antman
	$(RM) giantman/giantman

re: fclean all

.PHONY: all, clean, fclean, re
