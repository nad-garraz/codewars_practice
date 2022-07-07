/*
Your task is to determine the Next Lower Power of 2 to a given input number - or something like that...;-)

Here it's easy, you don't have to check errors or incorrect input values, every thing is ok without bad tricks, only int numbers as input and output;-)...
And please consider: You have to use bit shift operations to solve this
"problem", no multiplication, no Math.Pow() or **...

Some easy examples:

Input: 2     => Output: 1
Input: 7     => Output: 4
Input: 0     => Output: ?
Input: -128  => Output: -256
There are some static tests at the beginning and many random tests if you submit
your solution.

Perhaps you can look at Shifting Bits Next Higher Power too;-)?

Hope you have fun:-)!
*/

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int nextLower(int n);
int main(int argc, char *argv[]) {
  cout << nextLower(-1) << endl;
  cout << nextLower(-2) << endl;
  cout << nextLower(-4) << endl;
  cout << nextLower(-16) << endl;
  cout << nextLower(0) << endl;
  cout <<  nextLower(1) << endl;
  cout <<  nextLower(2) << endl;
  cout <<  nextLower(3) << endl;
  cout <<  nextLower(31) << endl;
  return 0;
}
/*
int nextLower(int n) {
 if ( n == 0 ) return -1;
 else if (n == 1 ) return 0;
 else if ( n < 0 ) {
  int min{-0b1};
  do {
  min <<= 1;
  } while (min >= n);
  return min;
   } else {
  int max{0b1};
  do {
  max <<= 1;
  } while ( max < n);
  return max >>= 1;
  }
}
 */

// Para aprender
//
int nextLower(int n)
{
  int cockroach {0};
  n-=1;
  while ( n > 1 or n < -1 ) {
    n >>= 1;
    ++cockroach;
  }
  return n << cockroach;
}
