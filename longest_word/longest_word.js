function longest_word(sentence) {
  // since the "word" does not include non-alpha characters, replace all
  // non-alpha characters with spaces
  var fixed_sentence = sentence.replace(/[^a-zA-Z]/g,' ');
  var longest_word = "";
  var longest_word_size = 0;
  var count = 0;
  var start = 0;
  var length = fixed_sentence.length;
  // loop over sentence and if there is a space, or if you reach the end of 
  // the word, then check if the current word is longer than the longest_word
  // if it is, create a substring that is the longest word
  for (var i = 0; i < length; i++) {
    if (fixed_sentence[i] == ' ' || (i + 1) == length) {
      if (count > longest_word_size) {
        longest_word_size = count;
        longest_word = fixed_sentence.substring(start, i);
      }
      start = i + 1;
      count = 0;
    }
    count++;
  }
  return longest_word;
}

console.log(longest_word("hellooooo!!**#world"))