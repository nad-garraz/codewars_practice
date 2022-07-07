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

#define ll long long

using namespace std;

ll dontGiveMeFive(ll s, ll e);
ll onlyFives(ll x);
bool has5(ll x);
bool lastIs9(ll x);
bool lastIs5(ll x);
long long unsigned invertNumber(ll x);
int digitos(ll x);
ll fivesFromOne(ll a);
ll dont5(ll s, ll e);

int main(int argc, char *argv[]) {
  cout << "NO 5s:     " << dontGiveMeFive(432352353, 134193874559384) << endl;
  cout << "NO 5s:     " << dontGiveMeFive(432352353, 134193874559386) << endl;
  cout << "NO 5s:     " << dontGiveMeFive(432352356, 134193874559386) << endl;
  cout << "NO 5s:     " << dontGiveMeFive(432352359, 134193874559389) << endl;
  cout <<  endl;
  cout <<  endl;
  cout <<  endl;
  cout <<  endl;
  cout <<  endl;

  cout << "NO 5s:     " << dontGiveMeFive(5, 15) << endl;
  cout << "Respuesta: 9" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-15, -5) << endl;
  cout << "Respuesta: 9" << endl;
  cout << endl;
  cout << "NO 5s:     " << dontGiveMeFive(984, 4304) << endl;
  cout << "Respuesta: 2449" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(2313, 2317) << endl;
  cout << "Respuesta: 4" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-4045, 2575) << endl;
  cout << "Respuesta: 4819" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-4436, -1429) << endl;
  cout << "Respuesta: 2194" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-5, 4) << endl;
  cout << "Respuesta: 9" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-5, -4) << endl;
  cout << "Respuesta: 1" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-5, 5) << endl;
  cout << "Respuesta: 9" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-1, 0) << endl;
  cout << "Respuesta: 2" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-1, 1) << endl;
  cout << "Respuesta: 3" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-3, 6) << endl;
  cout << "Respuesta: 9" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(51, 60) << endl;
  cout << "Respuesta: 1" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-206981731, 2235756979031654521)
       << endl;
  cout << "Respuesta: 340132150309630357" << endl;
  cout << "NO 5s:     "
       << dontGiveMeFive(-2490228783604515625, -2490228782196537011) << endl;
  cout << "Respuesta: 520812180" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(40076, 2151514229639903569) << endl;
  cout << "Respuesta: 326131553237897713" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(203832030, 8999999999655794863)
       << endl;
  cout << "Respuesta: 1200757082139598653" << endl;
  cout << "NO 5s:     " << dontGiveMeFive(-8999999998722592929, -2031011340)
       << endl;
  cout << "Respuesta: 1200757081080627486" << endl;
  cout << "NO 5s:     "
       << dontGiveMeFive(-9000000000000000000, 9000000000000000000) << endl;
  cout << "Respuesta: 2401514164751985937" << endl;

  return 0;
}

ll dontGiveMeFive(ll s, ll e) {
  bool lastIs5_e = lastIs5(e);
  bool lastIs5_s = lastIs5(s);
  bool lastIs9_e = lastIs9(e);
  bool lastIs9_s = lastIs9(s);
  ll no5s{};
  ll temp{};
  if (s < 0 and e <= 0) {
    temp = s;
    s = abs(e);
    e = abs(temp);
    no5s = e - onlyFives(e) - (s - onlyFives(s)) + 1;
    return (lastIs5_e or lastIs5_s) ? no5s -1 : no5s;
  } else if (s < 0 and e >= 0) {
    s = abs(s);
    no5s = e - onlyFives(e) + s - onlyFives(s) + 1;
    return (lastIs5_e or lastIs5_s) ? no5s : no5s;
  } else if (s >= 0 and e > 0) {
    /* e += has9_e ? 1 : 0;
    s += has9_s ? 1 : 0; */
    no5s = e - onlyFives(e) - (s - onlyFives(s)) + 1;
    // return (has5_e or has5_s) ? no5s + 1 : no5s;
    // no5s += ( s== 0 ) ? 1 : 0;
    return no5s;
  }
  return 0;
}

// devuelve la cantidad de números con "5" entre 1 y x.
ll onlyFives(ll x) {
  if (x <= 4) {
    return 0;
  } else if (x > 4 and x < 15) {
    return 1;
  }
  ll fives{}, digit{};
  ll orderOf_x = digitos(x);
  long long unsigned invX = invertNumber(x);
  while (orderOf_x >= 0) {
    digit = invX % 10;
    // numero que van de 1 a 4
    if (digit < 5) {
      fives += digit * fivesFromOne(powl(10, orderOf_x));
    }
    // numero que van de 6 a 9
    //  calcula por partes:
    //  1 - de 1 a 4
    //  2 - suma la contribución del 5 en su orden de magnitud
    //  3 - de 6 a 9
    else if (digit > 5) {

      fives += 5 * fivesFromOne(powl(10, orderOf_x)) + powl(10, orderOf_x) +
               (digit - 6) * fivesFromOne(powl(10, orderOf_x));
    } else {
      ll order = powl(10, orderOf_x);
      ll x_after_five = x % order;
      fives += 5 * fivesFromOne(powl(10, orderOf_x)) + 1 + x_after_five;
      break;
    }
    invX /= 10;
    --orderOf_x;
  }
  return fives;
}

// returns the amount of numbers with 5
// from 1 to a
ll fivesFromOne(ll x) {
  ll noFives{};
  ll total = has5(x) ? x + 1 : x;
  for (int i{}; x > 0; i++) {
    noFives += (x % 10) * powl(9, i);
    x /= 10;
  }
  return total - noFives;
}

// returns the total amount of digits of x
int digitos(ll x) {
  ll dig{};
  x = abs(x);
  while (x > 0) {
    x /= 10;
    dig++;
  }
  return dig - 1;
}

//  return TRUE if the number x has a 5
//  FALSE otherwise
bool has5(ll x) {
  x = abs(x);
  while (x != 0) {
    if (x % 10 == 5) {
      return true;
    }
    x /= 10;
  }
  return false;
}

bool lastIs9(ll x) {
  x = abs(x);
    if (x % 10 == 9) {
      return true;
    }
  return false;
}

bool lastIs5(ll x) {
  x = abs(x);
    if (x % 10 == 5) {
      return true;
    }
  return false;
}

long long unsigned invertNumber(ll n) {
  long long unsigned x = abs(n);
  if (x / 10 < 1)
    return x;
  long long unsigned rev{x % 10};
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
    if (has5(x)) {
      total -= 1;
      has_five += 1;
    }
  }
  // cout << "5s: " << has_five << endl;
  return total;
}
