CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

SRC = gtree.c print.c serialize.c

OBJS= $(SRC:.c=.o)

BIN = gtree

all: library

library:$(OBJS)
	ar csr libgtree.a $(OBJS)

clean:
	rm -rf *.o *.a a.out

.PHONY: clean
