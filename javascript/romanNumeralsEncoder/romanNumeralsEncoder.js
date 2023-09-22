/*
Create a function taking a positive integer between 1 and 3999 (both included) as its parameter and returning a string containing the Roman Numeral representation of that integer.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Example:

solution(1000); // should return 'M'
Help:

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
Remember that there can't be more than 3 identical symbols in a row.


*/

const dicc = {
  1: 'I',
  5: 'V',
  10: 'X',
  50: 'L',
  100: 'C',
  500: 'D',
  1000: 'M',
};

const O = (i) => 10 ** i;
const newArr = (d, i) => new Array(d % 5).fill(dicc[O(i)]).join('');
function solution(number) {
  return number.toString()
    .split('').reverse()
    .map((digit, idx) => {
      if (digit % 5 == 4) {
        return digit == 4
          ? dicc[O(idx)] + dicc[O(idx) * 5] // 4...
          : dicc[O(idx)] + dicc[O(idx + 1)]; // 9...
      } else {
        return digit < 5
          ? newArr(digit, idx) // 1, 2, 3 ...
          : dicc[O(idx) * 5] + newArr(digit, idx); // 5, 6, 7, 8...
      }
    }).reverse().join('');
}

console.log(solution(1990));
console.log(solution(1666));
console.log(solution(3999));
