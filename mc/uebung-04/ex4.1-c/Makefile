CC=gcc
CFLAGS=-Wpedantic -std=c99

calc: main.o getch.o getop.o stack.o
	$(CC) -lm $(CFLAGS) main.o getch.o getop.o stack.o -o calc
	rm -f *.o

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f calc
