CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -fsanitize=address

OBJS = dlist_init.o map.o get.o clear.o remove.o

library: libdlist.a

libdlist.a: $(OBJS)
	ar csr libdlist.a $(OBJS)

clean:
	$(RM) $(OBJS) $(RM) libdlist.a

.PHONY: all check clean
