def totient(num)
  primef = Prime.prime_division(num)
  tot = num
  primef.each do |p|
    tot *= 1 - (1.0/p[0])
  end
  return tot.to_i
end