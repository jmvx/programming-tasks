function add(num) {
  var sum = 0;
  for (var i = 1; i <= num; i++) {
    sum = sum + i;
  }
  return sum;
}

console.log(add(12));
console.log(add(140));