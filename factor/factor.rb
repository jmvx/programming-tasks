def factor(num)
  factors = Array.new
  (1..Math.sqrt(num)).each do |y| 
    if num % y == 0 then
       factors << [y,num/y] unless Math.sqrt(num) == y #or y == 1
    end
  end
  return factors
end