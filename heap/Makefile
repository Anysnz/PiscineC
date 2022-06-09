CC = gcc

CFALGS = -std=c99 -Wall -Wextra -Werror -pedantic

OBJS = create.o add.o pop.o del.o print.o

all: libheap.a

libheap.a: $(OBJS)
	ar csr libheap.a $(OBJS)

clean:
	$(RM) $(OBJS)

.PHONY : all check clean
