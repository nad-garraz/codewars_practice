/*
This is my republished first kata(with issues fixed!), hope you guys will enjoy
it!

For input, you will be given a string in the form "(mx+n)(px+q)" where the
character x can be any single lowercase alphabet from a-z, while m, n, p and q
are integers(can be negative).

Task
Return a string in the format ax^2+bx+c where a, b and c are integers, eg.
5x^2-6x+8 If a or b is 1, the '1' in front of the variable should be omitted.
eg. x^2+x-20 If a or b is -1, only the minus sign - should be shown, eg.
-x^2-x+6 Examples: KataSolution.quadraticBuilder("(x+2)(x+3)");  //return
"x^2+5x+6" KataSolution.quadraticBuilder("(x-2)(x+7)");  //return "x^2+5x-14"
KataSolution.quadraticBuilder("(3y+2)(y+5)");  //return "3y^2+17y+10"
KataSolution.quadraticBuilder("(-h-7)(4h+3)");  //return
"-4h^2-31h-21" Good luck and have fun!
*/

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

string quadratic_builder(const string &expression);
string fSign(long int a, string x, string op);

int main(int argc, char *argv[]) {
  // string s = "(2q+3)(2q-3) = ";
  string s = "(x+0)(x+1)   = ";
  cout << s ;
  cout << quadratic_builder(s) << endl;
  return 0;
}

// This function is to deal with the fact that the coefficient
// cannot be -1 or 1 or 0,
string fSign(long int a, string x, string op) {
  string str;
  if (a == -1 and x != "") {
    str = "-";
  } else {
    str = (a == 1 and x != "") ? "" : to_string(a);
  }
  return (a == 0) ? "" : op + str + x;
}

// Using regex extract the necesary elements and then
// convert that to long int to do the expansion.
// After that make a string with the format required.
string quadratic_builder(const string &s) {
  vector<long int> v{0, 0, 0, 0, 0};
  int i{};
  long int a0{}, a1{}, a2{};
  string x, str_a0, str_a1, str_a2, op0, op1;
  regex e(R"(\((-?\d?+)([a-z])([+-]\d+)\)\((-?\d?+)[a-z]([+-]\d+)\))");
  smatch m;
  regex_match(s, m, e);

  for (smatch::iterator it = m.begin() + 1; it != m.end(); ++it) {
    // cout << *it << endl;
    if (i == 1) {
      x = *it;
    } else {
      if (*it == "") {
        v[i] = 1;
      } else {
        v[i] = (*it == "-") ? -1 : stoll(*it);
      }
    }
    i++;
  }

  a2 = v[0] * v[3];
  a1 = v[0] * v[4] + v[2] * v[3];
  a0 = v[2] * v[4];

  op1 = (a1 <= 0) ? "" : "+";
  op0 = (a0 <= 0) ? "" : "+";

  str_a0 = (a0 == 0) ? "" : to_string(a0);

  string ans = fSign(a2, x + "^2", "") + fSign(a1, x, op1) + fSign(a0, "", op0);

  return ans;
}
