function atoi(str) {
  var last = str[str.length-1].charCodeAt(0) - 48;
  var last = (str[0] == "-" && last * -1) || last
  var new_str = str.slice(0,str.length-1);
  return (new_str != "" && new_str != "-") && (10 * atoi(new_str) + last) || last;
};