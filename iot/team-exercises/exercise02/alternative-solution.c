#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trim_left copies n bytes from buf starting at the given offset (from the
// left) to a new buffer, deallocates buf's memory and returns the new
// (smaller) buffer. The resulting buffer is delimited with the NULL character.
char *trim_left(char *buf, int offset, int n)
{
	// n + 1 for delimiter
	char *result = (char *)malloc((n + 1) * sizeof(char));

	result[n] = '\0';
	memcpy(result, buf + offset, n);
	free(buf);

	return result;
}

// binary converts the given number to its binary representation.
char *binary(unsigned int number)
{
	// eight chars per byte; no delimiter yet
	const int size = sizeof(number) * 8;
	char *buf = (char *)malloc(sizeof(char) * size);

	int i = size - 1;
	int n = 0;
	do {
		buf[i] = '0' + (number & 1);
		number = number >> 1;
		i--;
		n++;
	} while (number > 0);

	return trim_left(buf, i + 1, n);
}

// hexadecimal converts the given number to its hexadecimal representation.
char *hexadecimal(unsigned int number)
{
	// two chars per byte; no delimiter yet
	const int size = sizeof(number) * 2;
	char *buf = (char *)malloc(sizeof(char) * size);

	int i = size - 1;
	int n = 0;
	do {
		int hex = number & 0xf;
		if (hex < 10) {
			buf[i] = '0' + hex;
		} else {
			buf[i] = hex - 10 + 'a';
		}
		number = number >> 4;
		i--;
		n++;
	} while (number > 0);

	return trim_left(buf, i + 1, n);
}

// print_binary prints the given number both as its binary representation, and
// its hexadecimal (with leading 0x) representation.
void print_binary(unsigned int number)
{
	char *bin = binary(number);
	char *hex = hexadecimal(number);

	printf("%s 0x%s %u\n", bin, hex, number);

	free(bin);
	free(hex);
}

int main()
{
	print_binary(42);
	print_binary(65535);
	print_binary(0);
	print_binary(-1);
}

