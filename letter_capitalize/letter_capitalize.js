function capitalizeFirst(word) {
  return word.charAt(0).toUpperCase() + word.slice(1);
}

function titleCase(sentence) {
  var words = sentence.split(" ");
  var result = "";
  for (var i = 0; i < words.length; i++) {
    result = result.concat(capitalizeFirst(words[i]));
    if (i != words.length - 1) {
      result = result.concat(" ");
    }
  }
  return result;
}

console.log(titleCase("i ran there"));