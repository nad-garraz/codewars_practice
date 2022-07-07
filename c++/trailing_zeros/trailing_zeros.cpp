/*
Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 * ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros
Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.
*/



#include <iostream>
#include <cmath>

using namespace std;

long zeros(long n);

int main(int argc, char *argv[]) {
cout << zeros(30);
	return 0;
}

long zeros(long n) {
	long kmax = floor(log10(n) / log10(5));
	long Z{};
	for (long k = 1; k <= kmax; k++) {
		Z += n / pow(5, k);
	};
  return Z;
}
