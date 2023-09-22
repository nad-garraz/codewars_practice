/*
Just like in the "father" kata, you will have to return the last digit of the nth element in the Fibonacci sequence (starting with 1,1, to be extra clear, not with 0,1 or other numbers).

You will just get much bigger numbers, so good luck bruteforcing your way through it ;)

lastFibDigit(1) == 1
lastFibDigit(2) == 1
lastFibDigit(3) == 2
lastFibDigit(1000) == 5
lastFibDigit(1000000) == 5
*/

// 1,1,2,3,5,8,13,21,34,55,89
// 1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9

function lastFibDigit(n) {
  let a = 0;
  let b = 1;
  let c = a + b;
  while (n > 2) {
    a = b > 9 ? b % 10 : b;
    b = c > 9 ? c % 10 : c;
    c = a + b > 9 ? (a + b) % 10 : a + b;
    n--;
  }
  return c;
}

for (let i = 1000; i < 1001; i++) {
  console.log(lastFibDigit(i));
}
