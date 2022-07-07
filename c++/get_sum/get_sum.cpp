/*
	 Given two integers a and b, which can be positive or negative, find the sum of all the integers between and including them and return it. If the two numbers are equal return a or b.

Note: a and b are not ordered!

Examples (a, b) --> output (explanation)
(1, 0) --> 1 (1 + 0 = 1)
(1, 2) --> 3 (1 + 2 = 3)
(0, 1) --> 1 (0 + 1 = 1)
(1, 1) --> 1 (1 since both are same)
(-1, 0) --> -1 (-1 + 0 = -1)
(-1, 2) --> 2 (-1 + 0 + 1 + 2 = 2)
*/

#include <iostream>

using namespace std;
int get_sum(int a, int b);

int main(void) {
	cout << get_sum(3, 3);
	return 0;
}

int get_sum(int a, int b) {
	int sum{};
	for ( int i = min(a,b); i <= max(a,b); i++ ) {
		sum += i;
	};
	return sum;
}

// Para pensar:
/* int get_sum(int a, int b)
{
  int n = (a < b ? b - a : a - b) + 1;
  return n *(a + b)/ 2;
}
*/
