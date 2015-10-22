#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// copies and reverses an array of characters
void reverse_me(char* characters, int length) {
  int end = length - 1;
  for (int j = 0, i = end; j < end/2; j++, i--) {
    char temp = characters[i];
    characters[i] = characters[j];
    characters[j] = temp;
  }
}

void reverse_domain(char* domain, int length) {
  // reverse all the characters in the array
  reverse_me(domain, length);
  int start = 0; // defines start of the substring to be re-swap
  for (int i = 0; i <= length; i++) {
    // if you encounter a dot or the end of the character array
    // loop over the substring and re-swap each character
    if (domain[i] == '.' || domain[i] == '\0') {
      int substring_length = i - start;
      int end = i - 1; // so the dot isn't swapped
      for (int j = start, k = end; (j - start) < substring_length/2; j++, k--) {
        char temp = domain[j];
        domain[j] = domain[k];
        domain[k] = temp;
      }
      // move the start of the substring to the first character past the dot
      start = i + 1;
    }
  }
}

int main () {
  char* domain = strdup("mail.google.com");
  reverse_domain(domain, strlen(domain));
  puts(domain);
  free(domain);
  return 0;
}