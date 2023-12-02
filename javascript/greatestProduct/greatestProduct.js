/*
Complete the greatestProduct method so that it'll find the greatest product of five consecutive digits in the given string of digits.

For example:

greatestProduct("123834539327238239583") // should return 3240
The input string always has more than five digits.

Adapted from Project Euler.
*/

function greatestProduct(input) {
let p = 0,  max = 0;
  for (let i = 0; i < input.length-4; i++) {
    p = input.slice(i, 5+i).split("").reduce((d, acc) => acc * Number(d), 1);
    if (p > max) max = p
  }
  return max;
}

const input = '92494737828244222221111111532909999';
// const input = "02494037820244202221011110532909999";
console.log(greatestProduct(input));
