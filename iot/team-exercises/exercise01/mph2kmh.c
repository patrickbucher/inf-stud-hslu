#include <stdio.h>

int main() {
  float mph = 5.0;
    while (mph <= 100) {
      printf("%6.2f mph\t%6.2f km/h\n", mph, mph*1.60934);
      mph += 5;
    }
}
