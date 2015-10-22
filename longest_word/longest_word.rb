def longest_word(sentence)
  # replace non-alpha characters with spaces, reduce all multi-spaces to just
  # one space, strip any leading or trailing spaces, and then split words
  # into an array
  sentence = sentence.gsub(/[^a-zA-Z]/,' ').squeeze(' ').strip.split(' ')
  longest_word_size = 0;
  longest_word = ""
  # loop over each word and determine if the word size is longer than the
  # longest word size
  sentence.each do |word|
    if word.size > longest_word_size
      longest_word = word
      longest_word_size = word.size
    end
  end
  return longest_word
end

puts longest_word("hellooooo!!**#world")