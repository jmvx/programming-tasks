#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h> // for large integers

uint64_t factorial(uint64_t integer) {
  if (integer == 0) {
    return 1;
  }
  uint64_t answer = 1;
  // loop over digits between 1 and the integer
  for (uint64_t i = 1; i <= integer; i++) {
    // if current answer is too big for uint64_max
    if (answer > UINT64_MAX / i) {
      return 0;
    }
    // otherwise, compute the factorial
    answer *= i;
  }
  return answer;
}

int main (int argc, char** argv) {
  if (argc == 2) {
    uint64_t f = factorial(atoi(argv[1]));
    printf("%"PRIu64"\n", f);
  }
  return 0;