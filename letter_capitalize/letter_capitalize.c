#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

char* title_case(char* sentence) {
  size_t length = strlen(sentence);
  for (size_t i = 0; i < length; i++) {
    if (i == 0 || isspace(sentence[i-1])) {
      sentence[i] = sentence[i] - 32;
    }
  }
  return sentence;
}

int main () {
  const char* input = "hello world";
  const char* result = "Hello World";
  char* copy = strdup(input);
  copy = title_case(copy);
  assert(strcmp(copy,result) == 0);
  free(copy);
  return 0;
}