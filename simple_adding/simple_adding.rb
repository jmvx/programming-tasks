def add(num)
  (1..num).reduce(:+)
end

puts add(12) # should be 78
puts add(140) # should be 9870