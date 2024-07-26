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

bool isPrime(long long num);

int main(int argc, char *argv[])
{
  std::cout << isPrime(12) << std::endl;
  return 0;
}

bool isPrime(long long num)
{
  if (num == 2) return true;
  if (num <= 1 || num % 2 == 0) return false;

  for (long long tmp{3}; tmp * tmp <= num; tmp += 2)
  {
    if (num % tmp == 0) return false;
  }
  return true;
}
