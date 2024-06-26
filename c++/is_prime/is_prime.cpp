/*
	 Define a function that takes one integer argument and returns logical value true or false depending on if the integer is a prime.

	 Per Wikipedia, a prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.

	 Requirements
	 You can assume you will be given an integer input.
	 You can not assume that the integer will be only positive. You may be given negative numbers as well (or 0).
	 NOTE on performance: There are no fancy optimizations required, but still the most trivial solutions might time out. Numbers go up to 2^31 (or similar, depends on language version). Looping all the way up to n, or n/2, will be too slow.
	 Example
	 is_prime(1)  -> false
	 is_prime(2)  -> true
	 is_prime(-1) -> false
	 */



#include <iostream>
#include "../templates/templates.h"

using namespace std;

bool isPrime(long long num) {
	int j{};
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 or num % 3 == 0) return false;
	for (int i{5}; i * i <= num; i += 6) {
		if (num % i == 0 or num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {
	cout << isPrime(3) << endl;
	return 0;
}
