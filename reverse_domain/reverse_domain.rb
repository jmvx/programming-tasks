# reverses a string by swapping characters on opposite ends
def reverse_helper(word)
  b = 0
  e = word.length-1
  while b <= e do
    temp = word[b]
    word[b] = word[e]
    word[e] = temp
    b += 1
    e -= 1
  end
  return word
end

def reverse_domain(domain)
  # reverse characters in the domain to put words in correct locations
  # mail.google.com --> moc.elgoog.liam
  # add a final dot to signal the final reversal
  domain = reverse_helper(domain) + "."
  domain.each_char do |d|
    # go through each character until you reach a dot
    # get substring including the dot, then reverse it: moc. --> .com
    # append reversed string to domain and delete the original version
    if d == "."
      stop = domain.index(d) + 1
      domain << reverse_helper(domain[0,stop])
      domain = domain.sub(domain[0,stop], "")
    end
  end
  # return new domain excluding the extraneous preceeding dot
  # .com.google.mail --> com.google.mail
  return domain[1..-1]
end

puts reverse_domain("mail.google.com") # com.google.mail