#include <iostream>
#include <cmath>

#define ll long long

using namespace std;
bool has5(ll x);
ll dont5(ll s, ll e);


int main(void) {
  cout << "NO 5s: " << dont5(-5,5) << endl;
  cout << "NO 5s: " << dont5(-5, 5) << endl;
  cout << "NO 5s: " << dont5(0, 1)  << endl;
  cout << "NO 5s: " << dont5(5, 15) << endl;
  cout << "NO 5s: " << dont5(-5, 4) << endl;
  cout << "NO 5s: " << dont5(51, 60) << endl;
  cout << "NO 5s: " << dont5(1, 40076) << endl;

  cout << powl(10,18) <<endl;

return 0;
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

ll dont5(ll s, ll e) {
  ll total = e - s + 1;
  ll has_five{};
  for (ll x{s}; x <= e; ++x) {
    if (has5(abs(x))) {
      total -= 1;
      has_five += 1;
    }
  }
  return total;
}
