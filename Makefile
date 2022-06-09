CC= gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
OBJ = list.o list_print.o

list: $(OBJ)
	$(CC) $(OBJ) -o list