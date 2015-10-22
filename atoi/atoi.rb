def atoi_v1(string)
  def atoi_helper(string, number)
    first = string.ord - 48
    mult = 10**(string.length-1)
    number += first*mult
    new_string = string[1,string.length-1]
    return ((new_string != "") && atoi_helper(new_string, number)) || number
  end
  return atoi_helper(string, 0)
end