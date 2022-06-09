CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -fsanitize=address

OBJS = clear.o init.o

library: libfifo.a

libfifo.a: $(OBJS)
	ar csr libfifo.a $(OBJS)

clean:
	$(RM) $(OBJS) $(RM) libfifo.a

.PHONY: all check clean
