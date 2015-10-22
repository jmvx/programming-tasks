// reverses a string by concatenating characters to empty string
// starting at the end of the original string
function reverse_me(word) {
  var reversed_word = "";
  for (var i = word.length - 1; i >= 0; i--) {
    reversed_word = reversed_word.concat(word[i]);
  }
  return reversed_word;
}

function reverse_domain(domain) {
  // reverse domain to put words in correct locations, fix characters after
  // then append a final dot (will be used to signal the final reversal)
  // mail.google.com --> moc.elgoog.liam.
  var rev_domain = reverse_me(domain) + ".";
  var answer = "";
  var start_substring = 0;
  // loop over the reversed domain. Whenever you hit a dot, get the substring
  // including that dot, reverse it, and append it to the 'answer' string
  // moc. --> .com --> .com.google --> .com.google.mail
  for (var i = 0; i < rev_domain.length; i++) {
    if (rev_domain[i] == ".") {
      substring = rev_domain.substring(start_substring,i+1);
      answer = answer.concat(reverse_me(substring));
      start_substring = i+1;
    }
  }
  // remove the extraneous dot at the front of the new domain string
  return answer.substring(1,answer.length);
}

console.log(reverse_domain("mail.google.com"))