/*
Palindromic Numbers
A palindromic number is a number that remains the same when its digits are reversed. Like 16461, for example, it is "symmetrical".

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number.

Lychrel Numbers
It is not known whether all non-palindromic numbers can be paired with palindromic numbers in this way. While no number has been proven to be unpaired, many do not appear to be. For example, 196 does not yield a palindrome even after 700,000,000 iterations. Any number that never becomes palindromic in this way is known as a Lychrel number.

This Kata is about actually finding a palindromic number out of an original seed.

You will be given a number as input and in the output you must return a string containing the number of iterations (i.e. additions) you had to perform to reach the palindromic result and the palindromic number itself, separated by a space. In Haskell return a tuple (Int, Integer).

palindromize(195) == 4 9339
palindromize(265) == 5 45254
palindromize(750) == 3 6666
Some Assumptions
You can assume that all numbers provided as input will be actually paired with a palindromic result and that you will reach that result in less than 1000 iterations and yield a palindrome.
*/

const reverse = (n) => Number(n.toString().split('').reverse().join(''));
function palindromize(number) {
  let iterations = 0;
  while (true) {
    if (number === reverse(number)) {
      return `${iterations} ${number}`;
    } else {
      number += reverse(number);
      iterations++;
    }
  }
}

console.log(palindromize(195));
console.log(palindromize(750));
console.log(palindromize(6666));
console.log(palindromize(2));
console.log(palindromize(265));
