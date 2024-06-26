/*
Convert number to reversed array of digits
Given a random non-negative number, you have to return the digits of this number
within an array in reverse order.

Example(Input => Output):
35231 => [1,3,2,5,3]
0 => [0]

*/

#include <iostream>
#include <vector>

std::vector<int> digitize(unsigned long n);

int main()
{
  for (auto item : digitize(0))
    std::cout << item << ",";
  return 0;
}

std::vector<int> digitize(unsigned long n)
{
std::vector<int> ans{0};
  if(n == 0) return ans;  
  ans.pop_back();
  while (n){
    ans.push_back(n % 10);
    n /= 10;
  }
  return ans;
}
