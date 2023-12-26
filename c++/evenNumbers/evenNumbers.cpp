/*
Given an array of numbers, return a new array of length number containing the
last even numbers from the original array (in the same order). The original
array will be not empty and will contain at least "number" even numbers.

For example:

([1, 2, 3, 4, 5, 6, 7, 8, 9], 3) => [4, 6, 8]
([-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26], 2) => [-8, 26]
([6, -25, 3, 7, 5, 5, 7, -3, 23], 1) => [6]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> evenNumbers(vector<int> arr, int n);

int main() {
  for (auto item : evenNumbers({1,2, 2, 3, 5, 7, 9, 10, 12}, 4)) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}

vector<int> evenNumbers(vector<int> arr, int n) {
  vector<int> answer;
  for (auto it = arr.rbegin(); it != arr.rend() && static_cast<int>(answer.size()) < n; ++it) {
    if ( *it % 2 == 0){
      answer.insert(answer.begin(), *it);
    };
  }
  return answer;
}
