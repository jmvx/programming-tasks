#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_domain(const char* domain) {
  // allocate memory for reversed domain
  int length = strlen(domain);
  char* reversed = malloc(length + 1);
  reversed[length] = '\0';
  int end = length - 1;
  int k = 0;
  // loop over domain in reverse until you reach a dot or run out of characters
  // copy over each character
  for (int i = length - 1; i >= 0; i--) {
    if (domain[i - 1] == '.' || i - 1 < 0) {
      for (int j = i; j <= end; j++) {
        reversed[k] = domain[j];
        k++;
      }
      if (i - 1 >= 0) {
        reversed[k] = '.';
        k++;
      }
      end = i - 2;
    }
  }
  return reversed;
}

int main (int argc, char** argv) {
  if (argc == 2) {
    char* r = reverse_domain(argv[1]);
    puts(r);
    free(r);
  }
  return 0;
}