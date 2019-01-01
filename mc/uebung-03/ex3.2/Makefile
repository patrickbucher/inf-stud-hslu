all: main test

main: main.c division.c
	gcc -Wpedantic -std=c99 -o main main.c division.c

test: division_test.c division.c
	gcc -Wpedantic -std=c99 -o test division_test.c division.c

clean:
	rm -r main test
