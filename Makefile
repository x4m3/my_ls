##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## try not to segfault, good luck :)
##

CFLAGS += -Wall -Wextra -Iinclude
LDFLAGS +=
CC = cc

INC = include/my_ls.h
OBJ = $(SRC:c=o)
SRC = src/my_ls.c \

all: my_ls

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

my_ls: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) my_ls

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
