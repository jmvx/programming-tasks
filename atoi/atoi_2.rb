def atoi_v2(string)
  last = string[string.length-1].ord - 48
  last = (string[0] == "-" && last * -1) || last
  new_string = string[0,string.length-1]
  return ((new_string != "" && new_string != "-") && 10 * atoi_v2(new_string) + last) || last
end