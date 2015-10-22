// checks if character is a letter
function isAlpha(character) {
  var regex = /[a-zA-Z]/;
  var matches = character.match(regex);
  return matches ? true : false;
}

// checks if character is a vowel
function isVowel(character) {
  var regex = /[aeiouAEIOU]/;
  var matches = character.match(regex);
  return matches ? true : false;
}

// returns the next character and capitalizes it if it's a vowel
function nextChar(character) {
  var code = character.charCodeAt(0) + 1;
  // loop back to 'A' or 'a' when needed
  if (code == 91) {
    code = 65;
  }
  if (code == 123) {
    code = 97;
  }
  var char = String.fromCharCode(code);
  return isVowel(char) ? char.toUpperCase() : char;
}

function letterChanges(str) {
  var newStr = "";
  for (var i = 0; i < str.length; i++) {
    if (isAlpha(str[i])) {
      newStr = newStr.concat(nextChar(str[i]));
    }
    else {
      newStr = newStr.concat(str[i]);
    }
  }
  return newStr;
}

console.log(letterChanges("fun times!"));