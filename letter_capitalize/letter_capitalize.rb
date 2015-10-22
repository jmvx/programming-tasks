# alternative to .titleize or .titlecase
def title_case(sentence)
  words = sentence.split(' ')
  words.each do |word|
    word[0] = word[0].capitalize
  end
  words = words.join(' ')
end

puts title_case("hello world")
puts title_case("i ran there")