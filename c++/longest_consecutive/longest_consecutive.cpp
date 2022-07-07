/*
         You are given an array(list) strarr of strings and an integer k. Your
task is to return the first longest string consisting of k consecutive strings
taken in the array.

Examples:
strarr = ["tree", "foling", "trashy", "blue", "abcdef", "uvwxyz"], k = 2

Concatenate the consecutive strings of strarr by 2, we get:

treefoling   (length 10)  concatenation of strarr[0] and strarr[1]
folingtrashy ("      12)  concatenation of strarr[1] and strarr[2]
trashyblue   ("      10)  concatenation of strarr[2] and strarr[3]
blueabcdef   ("      10)  concatenation of strarr[3] and strarr[4]
abcdefuvwxyz ("      12)  concatenation of strarr[4] and strarr[5]

Two strings are the longest: "folingtrashy" and "abcdefuvwxyz".
The first that came is "folingtrashy" so
longest_consec(strarr, 2) should return "folingtrashy".

In the same way:
longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta",
"abigail"], 2) --> "abigailtheta" n being the length of the string array, if n =
0 or k > n or k <= 0 return "" (return Nothing in Elm).

Note
consecutive strings : follow one after another without an interruption
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LongestConsec {
public:
  static string longestConsec(vector<string> &strarr, int k) {
    int max{}, l{};
    string ans = "", str = "";
    int size = strarr.size();
    if (size == 0 or k > size or k <= 0)
      return "";

    for (int i{}; i <= size - k; i++) {

      for (int j = i; j < i + k; j++) {
        str += strarr[j];
      };
      l = str.size();
      cout << l << endl;
      if (max < l) {
        max = l;
        ans = str;
      }
      str = "";
      l = 0;
    };
    return ans;
  };
};

int main(void) {
  LongestConsec lc;
  vector<string> vec = {"zone", "abigail", "theta", "form",
                        "libe", "zas",     "theta", "abigail"};

  // vector<string> vec = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx",
  // "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
  cout << lc.longestConsec(vec, 1) << endl;
  return 0;
}
