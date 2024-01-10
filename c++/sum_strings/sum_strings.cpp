/*
Given the string representations of two integers, return the string
representation of the sum of those integers.

For example:

sumStrings('1','2') // => '3'
A string representation of an integer will contain no characters besides the ten
numerals "0" to "9".

I have removed the use of BigInteger and BigDecimal in java

Python: your solution need to work with huge numbers (about a milion digits),
converting to int will not work.
*/

#include <iostream>
#include <iterator>
#include <string>

std::string sum_strings(const std::string &a, const std::string &b);
int         recursiveFactorial(int n);

int main(int argc, char *argv[])
{

  std::cout << sum_strings("835", "2994") << std::endl;
  std::cout << recursiveFactorial(4) << std::endl;
  return 0;
}

std::string sum_strings(const std::string &a, const std::string &b)
{
  std::string up   = a.size() >= b.size() ? a : b;
  std::string down = up == a ? b : a;

  std::cout << "Up: " << up << std::endl;
  std::cout << "Down: " << down << std::endl;

  for (auto &letra : up)
  {
    std::cout << (letra - 48) << std::endl;
    std::cout << "Index: " << &letra - &up[0] << std::endl;
  }
  return "";
}

int recursiveFactorial(int n)
{
  if (n <= 1) return 1;
  return n * recursiveFactorial(n - 1);
}
