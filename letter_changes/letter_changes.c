#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// is alpha exists already

bool isvowel(char c) {
  if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || 
      c == 'O' || c == 'o' || c == 'U' || c == 'u') {
      return true;
  }
  return false;
}

int main() {
  char* input = "fun times!";
  int length = strlen(input);
  for (int i = 0; i < length; i++) {
    printf("%d\n", isvowel(input[i]));
  }
  return 0;
}