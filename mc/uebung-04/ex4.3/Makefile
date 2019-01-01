CC=gcc
CFLAGS=-Wpedantic -std=c99

ampel: main.o ampel.o
	$(CC) $(CFLAGS) main.o ampel.o -o ampel

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f ampel
