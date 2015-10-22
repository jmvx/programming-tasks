function factorial(number) {
  if (number == 0) {
    return 1;
  }
  var number_as_array = [];
  for (var i = 1; i <= number; i++) {
    number_as_array.push(i);
  }
  return number_as_array.reduce(function (a, b) {
    return a * b;
  });
}

console.assert(factorial(4) == 24);
console.assert(factorial(8) == 40320);