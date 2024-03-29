/*
Consider a sequence u where u is defined as follows:

1 - The number u(0) = 1 is the first one in u.
2 - For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
3 - There are no other numbers in u.
Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22
and so on...

Task:
Given parameter n the function dbl_linear (or dblLinear...) returns the element
u(n) of the ordered (with <) sequence u (so, there are no duplicates).

Example:
dbl_linear(10) should return 22
dbl_linear(100) should return 447
dbl_linear(6000) should return 80914
dbl_linear(100000) should return 2911593

Note:
Focus attention on efficiency
*/

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class DoubleLinear {
public:

bool alreadyInSequence(vector<int> &sequence, int y) {
    for (int j = 0; j < sequence.size(); ++j) {
      if (y == sequence[j]) {
        return true;
      }
    }
    return false;
  }

  int dblLinear(int n) {
    vector<int> sequence;
    sequence.push_back(1);

    sequence[0] = 1;

    int y{}, z{};
    int i{}, next{1}, add{1}, size{1};
    while (i < n) {
      y = 2 * next + 1;
      z = y + next;
      if (alreadyInSequence(sequence, y)) {
        sequence[add] = z;
        add++;
      } else {
        if (y < sequence[i + 1]) {
          sequence[add] = sequence[i + 1];
          sequence[i + 1] = y;
          sequence[add + 1] = z;
          add += 2;
        } else {
          sequence[add] = y;
          sequence[add + 1] = z;
          add += 2;
        }
      }
      size += add;
      ++i;
      next = sequence[i];
    }
    for (int j{}; j < n; j++) {
      cout << sequence[j] << endl;
    }

    return 0;
  }
};



// #include <algorithm>
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// class DoubleLinear {
// public:
//   bool alreadyInSequence(vector<int> &sequence, int y) {
//     for (int j = 0; j < sequence.size(); ++j) {
//       if (y == sequence[j]) {
//         return true;
//       }
//     }
//     return false;
//   }
//
//   int dblLinear(int n) {
//     vector<int> sequence;
//     sequence.push_back(1);
//
//     int y, z;
//     int i = 0, next = 1, add, size = 1;
//     while (i < n - 1) {
//       y = 2 * sequence[next] + 1;
//       z = sequence[next] + 3;
//
//       if (alreadyInSequence(sequence, y)) {
//         sequence.push_back(z);
//         add = sequence.size() - 1;
//       } else {
//         add = i + 1;
//         while (add < sequence.size() && y > sequence[add]) {
//           add++;
//         }
//         sequence.insert(sequence.begin() + add, y);
//         sequence.insert(sequence.begin() + add + 1, z);
//       }
//
//       size += add;
//       ++i;
//       next = i;
//     }
//
//     return sequence[n];
//   }
// };
//




int main(int argc, char *argv[]) {
  DoubleLinear Dl;
  cout << Dl.dblLinear(6000) << endl;
  return 0;
}
