CC=gcc
CFLAGS=-Wall -g

all: ex1 ex2

ex1: ex1.c
	$(CC) $(CFLAGS) $^ -o $@

ex2: ex2.c
	$(CC) $(CFLAGS) $^ -o $@

memcheck: ex2
	valgrind ./ex2

clean:
	rm -f ex1 ex2
