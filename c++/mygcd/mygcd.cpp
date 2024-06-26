/*
Find the greatest common divisor of two positive integers. The integers can be
large, so you need to find a clever solution.

The inputs x and y are always greater or equal to 1, so the greatest common
divisor will always be an integer that is also greater or equal to 1.
*/

#include <iostream>

long long mygcd(long long a, long long b);

int main()
{
  std::cout << mygcd(600, 450);
  return 0;
}

long long mygcd(long long a, long long b)
{
  if (b == 0)
    return a;

  return mygcd(b, a % b);
}

// long long mygcd(long long a, long long b)
// {
//   if (a == b) return a;
//
//   long long max, min, temp;
//   max  = a > b ? a : b;
//   min  = a < b ? a : b;
//
//   temp = min;
//   while (temp >= 1)
//   {
//     if (min % temp == 0 && max % temp == 0)
//     {
//       return temp;
//     }
//     else
//     {
//       temp--;
//     }
//   }
//   return temp;
// }
