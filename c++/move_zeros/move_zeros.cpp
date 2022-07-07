/*
Write an algorithm that takes an array and moves all of the zeros to the end,
preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> move_zeroes(const std::vector<int> &input);

int main(int argc, char *argv[]) {
    move_zeroes({});
	return 0;
}

std::vector<int> move_zeroes(const std::vector<int> &input) {
  /* std::vector<int> ans{};
  int zeros{};
  for (auto v : input) {
    if (v != 0) {
      ans.push_back(v);
    } else {
      zeros++;
    }
  }
  ans.insert(ans.end(), zeros, 0);
 */
std::vector<int> ans = input;
  for (int i{}; i < ans.size(); i++) {
    if (ans[i] == 0) {
      ans.erase(ans.begin() + i);
			ans.push_back(0);
    }
  }
  return ans;
}
