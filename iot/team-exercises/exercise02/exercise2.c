#include <stdio.h>

void print_binary(unsigned int number) {

  unsigned int size = 8*sizeof(unsigned int);
  char binary[size+1];
  for (int i = 0; i < size; i++) {
    binary[i] = (number << i) & (1 << (size-1)) ? '1' : '0';
  }
  binary[size] = '\0';

  printf("%10u\t%8x\t%s\n", number, number, binary);
}

int main() {
  print_binary(42);
  print_binary(65535);
  print_binary(0);
  print_binary(-1);
}