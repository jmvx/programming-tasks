# uses a regex to determine whether the character is a letter
def alpha?(character)
  character.match(/^[[:alpha:]]/)
end

# uses a regex to determine whether the character is a vowel
def vowel?(character)
  character.match(/[aeiou]/)
end

# loops over each character in the string, increments each letter, and 
# changes vowels to uppercase
# FIXME: z --> Aa
def letter_changes(sentence)
  i = 0
  sentence.each_char do |c|
    if alpha?(c)
      sentence[i] = c.next
      if vowel?(c.next)
        sentence[i] = sentence[i].upcase
      end
    end
    i = i + 1
  end
  return sentence
end

sentence = "fun times!z"
puts letter_changes(sentence)