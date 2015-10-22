def factorial(int)
  if int == 0
    return 1
  else
    return (1..int).reduce(:*)
  end
end