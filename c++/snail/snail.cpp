/*
Given an n x n array, return the array elements arranged from outermost elements
to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array
consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest;
the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array
[[]].


*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> snail(const vector<vector<int>> &snail_map);
vector<int> generate_sequence(int n);

int main(int argc, char *argv[]) {
  // vector<int> ans = snail({{}});
  // vector<int> ans = snail({{1}});
  // vector<int> ans = snail({{1, 2}, {4, 3}});
  // vector<int> ans = snail({{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
  vector<int> ans =
      snail({{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}});
  for (auto item : ans)
    cout << item << endl;
  return 0;
}

// if n = 6 returns [555,44,33,22,11]
// if n = 5 returns [444,33,22,11] and so on,,,
vector<int> generate_sequence(int n) {
  n--;
  vector<int> ans{n};
  for (int i{n}; i > 0; --i) {
    ans.push_back(i);
    ans.push_back(i);
  }
  return ans;
}

vector<int> snail(const vector<vector<int>> &snail_map) {
  size_t s = snail_map.size();
  // edge cases
  if (s == 0 || s == 1) return snail_map[0];

  int row{}, col{}, j{};
  size_t m = s * s; // total elements of matrix
  vector<int> v{snail_map[0][0]}, seq{generate_sequence(s)};

  while (true) {
    for (int elements{1}; elements <= seq[j]; ++elements) {
      switch (j % 4) {
        case(0) : col++; break;
        case(1) : row++; break;
        case(2) : col--; break;
        case(3) : row--; break;
        }
      v.push_back(snail_map[row][col]);
      if (v.size() == m) return v; // finish
      }
    j++;
  }
}

