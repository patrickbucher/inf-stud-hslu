CC=gcc
CFLAGS=-g -Wpedantic -std=c99

address: address.o fileio.o main.o sorting.o readline.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

debug: address
	valgrind --leak-check=full --show-leak-kinds=all ./address 2> valgrind.log

clean:
	rm -f *.o
	rm -f address
	rm -f vgcore*
	rm -f valgrind.log
