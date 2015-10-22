#include <stdio.h>

int add(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum = sum + i;
  }
  return sum;
}

int main() {
  printf("%d\n", add(12));
  printf("%d\n", add(140));
}