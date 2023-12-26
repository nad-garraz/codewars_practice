/*
You will be given a string and you task is to check if it is possible to convert
that string into a palindrome by removing a single character. If the string is
already a palindrome, return "OK". If it is not, and we can convert it to a
palindrome by removing one character, then return "remove one", otherwise return
"not possible". The order of the characters should not be changed.

For example:

solve("abba") = "OK". -- This is a palindrome
solve("abbaa") = "remove one". -- remove the 'a' at the extreme right.
solve("abbaab") = "not possible".
More examples in the test cases.

Good luck!

If you like this Kata, please try Single Character Palindromes II


*/

#include <iostream>
#include <string>

using namespace std;

string solve(string s);
string reverseString(string s);

int main(int argc, char *argv[]) {
  // cout << reverseString("123") << endl;
  string s = "aabba";
  cout << solve(s) << endl;
  return 0;
}

string solve(string s) {
  if (s == string(s.rbegin(), s.rend()))
    return "OK";

  for (size_t i{}; i < s.size(); i++) {
    string tempString = s;
    tempString.erase(i, 1);
    if (tempString == string(tempString.rbegin(), tempString.rend()))
      return "remove one";
  }
  return "not possible";
}

// // Invierte un string. Pero lo cambié por una opción más
// // elegante, usando string(s.rbegin()...)
//
// string reverseString(string s) {
//   string reverseString = "";
//   for (auto it = s.rbegin(); it != s.rend(); ++it)
//     reverseString += *it;
//   return reverseString;
// }
