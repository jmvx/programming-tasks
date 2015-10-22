#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// converts input character to lowercase and checks if it matches a vowel
bool isvowel(char c) {
  switch(tolower(c)) {
    case 'a': 
    case 'e':
    case 'i':
    case 'o':
    case 'u': return true;
    default: return false;
  }
}

int main() {
  // input string and resulting output string (for testing purposes)
  const char* input = "fun times!Z";
  const char* result = "gvO Ujnft!A";
  
  // create a mutable copy
  char* copy = strdup(input);
  size_t length = strlen(copy);
  for (size_t i = 0; i < length; i++) {
    // do not mutate punctuation or whitespace
    if (!ispunct(copy[i]) && !isspace(copy[i])) {
      // checks if character is 'z' and loops around to beginning of alphabet
      // change character to value of next character in alphabet
      if (tolower(copy[i]) != 'z') {
        copy[i] = copy[i] + 1;
      }
      else if (tolower(copy[i]) == 'z') {
        copy[i] = 'a';
      }
      // capitalize any vowels
      if (isvowel(copy[i]) && islower(copy[i])) {
        copy[i] = toupper(copy[i]);
      }
    }
  }
  // print resulting string and check that input and result match
  puts(copy);
  assert(strcmp(copy,result) == 0);
  // free memory
  free(copy);
  return 0;
}