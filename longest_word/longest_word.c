#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* longest_word(const char* sentence) {
  // allocate enough memory for a longest word that contains every character
  // in the sentence.
  int length = strlen(sentence);
  char* longest_word = malloc(length + 1);
  int longest_word_length = 0;
  int count = 0;
  int start = 0;
  // loop over the sentence and count the number of alpha characters that
  // appear in a row.
  // if the number of alpha characters becomes greater than the length of the
  // current longest_word, then update the information about the longest word
  for (int i = 0; i < length; i++) {
    if (isalpha(sentence[i]) == 0 || i + 1 == length) {
      if (count > longest_word_length) {
        longest_word_length = count;
        for (int j = 0, k = start; j < longest_word_length; j++, k++) {
          longest_word[j] = sentence[k];
        }
        longest_word[longest_word_length] = '\0';
      }
      start = i + 1;
      count = 0;
    }
    else {
      count++;
    }
  }
  return longest_word;
}

int main() {
  char* word = longest_word("helo&&***woiiijld***djjjjjjjjjjjjjjk");
  puts(word);
  free(word);
  return 0;
}