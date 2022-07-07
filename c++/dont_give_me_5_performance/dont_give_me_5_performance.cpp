/*
This kata is the performance version of Don't give me five by user5036852.

Your mission, should you accept it, is to return the count of all integers in a
given range which do not contain the digit 5 (in base 10 representation). You
are given the start and the end of the integer range. The start and the end are
both inclusive.

Examples:

1,9 -> 1,2,3,4,6,7,8,9 -> return 8
4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> return 12
The result may contain fives. ;-)
The start will always be smaller than the end. Both numbers can be also
negative.

The regions can be very large and there will be a large number of test cases. So
brute force solutions will certainly time out!

Good luck, warrior!


*/

#include <cmath>
#include <iostream>
#include <climits>

#define ll long long

using namespace std;

ll dontGiveMeFive(ll s, ll e);
unsigned long long OnlyFives(ll x);
bool has5(ll x);
ll invertNumber(ll x);
unsigned long long digitos(ll x);
ll FivesFrom1(ll a);
ll dont5(ll s, ll e);
ll howMany5(ll x);
int main(int argc, char *argv[]) {

  // cout << "NO 5s: " << dontGiveMeFive(0, 9'000'000'000'000'000'000) << endl; // Equals (2401514164751985937
  cout << "NO 5s: " << dontGiveMeFive(-9'000'000'000'000'000'000, 9'000'000'000'000'000'000) << endl; // Equals (2401514164751985937
}

ll dontGiveMeFive(ll s, ll e) {
  unsigned long long gap = e - s + 1;
  if (gap <= 2'000'000) {
    return dont5(s, e);
  }

  bool has5_end = has5(abs(e));
  bool has5_start = has5(abs(s));
  unsigned long long no5s{};
  unsigned long long total{};
  ll temp{};
  if (s <= 0 and e <= 0) {
    temp = s;
    s = abs(e);
    e = abs(temp);
    total = e - s + 1;
    no5s = total - (OnlyFives(e) - OnlyFives(s));
    return (has5_end or has5_start) ? no5s - 1 : no5s;
  } else if (s <= 0 and e >= 0) {
    s = -s;
    total = e + s + 1;
    no5s = total - (OnlyFives(e) + OnlyFives(s));
    return (has5_end or has5_start) ? no5s : no5s;
  } else {
    total = e - s + 1;
    no5s = total - (OnlyFives(e) - OnlyFives(s));
    return (has5_end or has5_start) ? no5s - 1 : no5s;
  }
}

unsigned long long OnlyFives(ll x) {
  if (x < 4 ) return 0;
  unsigned long long fives{};
  unsigned long long digitsOfX = digitos(x);
  ll invX = invertNumber(x);
  ll digit{};
  while (digitsOfX > 0) {
    digit = invX % 10;
    if (digit < 5) {
      fives += FivesFrom1(digit * pow(10, digitsOfX));
    } else if (digit > 5) {
        unsigned long long upper = FivesFrom1(pow(10, digitsOfX + 1));
        unsigned long long lower = (10 - digit) * FivesFrom1(pow(10, digitsOfX));
      fives += upper - lower;
    } else {
      unsigned long long numero = pow(10, digitsOfX - 1);
      invX = x % numero;
      // cout << invX << endl;
      // cout << digitsOfX << endl;
      fives += FivesFrom1(pow(10, digitsOfX + 1)) - 4 * FivesFrom1(pow(10, digitsOfX)) - (pow(10, digitsOfX) - invX) + 1;
      break;
    }
    invX /= 10;
    --digitsOfX;
  }
  return fives;
}

ll FivesFrom1(ll a) {
  ll fives{};
  ll total{a};
  for (int i{}; a > 0; i++) {
    fives += (a % 10) * pow(9, i);
    a /= 10;
  }
  return total - fives;
}

unsigned long long digitos(ll x) {
  unsigned long long dig{};
  x = abs(x);
  while (x > 0) {
    x /= 10;
    dig++;
  }
  return dig - 1;
}

bool has5(ll x) {
  while (x != 0) {
    if (x % 10 == 5) {
      return true;
    }
    x /= 10;
  }
  return false;
}

ll invertNumber(ll x) {
  x = abs(x);
  if (x / 10 < 1)
    return x;
  ll rev{x % 10};
  x /= 10;
  while (x > 0) {
    rev *= 10;
    rev += x % 10;
    x /= 10;
  }
  return rev;
}
ll dont5(ll s, ll e) {
  ll total = e - s + 1;
  ll has_five{};
  for (ll x{s}; x <= e; ++x) {
    if (has5(abs(x))) {
      total -= 1;
      has_five += 1;
    }
  }
  // cout << "5s: " << has_five << endl;
  return total;
}




//===================================================
//NOT USED




ll howMany5(ll n) {
  if (n == 0)
    return 19;
  if (n == 1)
    return 252;
  return (floor((howMany5(n - 1) - pow(10, n)) * (9.0 / 8.0)) + pow(10, n)) *
             8 +
         pow(10, n + 1);
}
