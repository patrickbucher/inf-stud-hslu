CC=gcc
CFLAGS=-Wpedantic -std=c99

main: main.c
	$(CC) $(CFLAGS) -g -D DEBUG -o main main.c

debug: newMain.c readline.c
	$(CC) $(CFLAGS) -g -D DEBUG -c -o readline.o readline.c
	$(CC) $(CFLAGS) -g -D DEBUG -c -o newMain.o newMain.c
	$(CC) $(CFLAGS) -o debug newMain.o readline.o
	rm -f *.o

release: newMain.c readline.c
	$(CC) $(CFLAGS) -c -o readline.o readline.c
	$(CC) $(CFLAGS) -c -o newMain.o newMain.c
	$(CC) $(CFLAGS) -o release newMain.o readline.o
	rm -f *.o

clean:
	rm -f *.o debug release main
