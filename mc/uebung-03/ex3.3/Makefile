wordcount: wordcount.c
	gcc -g -Wpedantic -std=c99 -o wordcount wordcount.c

run: wordcount input.txt
	./wordcount <input.txt | sort -rn
	rm -f wordcount

clean:
	rm -f wordcount
