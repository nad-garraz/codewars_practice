/*
This is a question from codingbat

Given an integer n greater than or equal to 0, create and return an array with the following pattern:

squareUp(2) => [0, 1, 2, 1]
squareUp(3) => [0, 0, 1, 0, 2, 1, 3, 2, 1]
squareUp(4) => [0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1]
n<=1000.

Check out my other kata!
Matrix Diagonal Sort OMG

String -> N iterations -> String

String -> X iterations -> String

ANTISTRING

Array - squareUp b!

Matrix - squareUp b!

Infinitely Nested Radical Expressions

pipi Numbers!
*/


#include <cstddef>
#include <iostream>
#include <vector> 

using namespace std;

vector<int> squareUp(int n);
vector<int> reverseArray(vector<int> v);

int main() {
  vector<int> vector = squareUp(2);
  for (int item : vector){
    cout << item << " ";
  }
	return 0;
}

vector<int> squareUp(int n) {
 vector<int> answer; 
  for (int i{}; i < n; i++){
    for (int j{1};  j <= n-i; j++) {
      answer.push_back(j);
    }
    for(int k{}; k < i; k++){
      answer.push_back(0);
    }
  } 
 return reverseArray(answer);
}

vector<int> reverseArray(vector<int> v){
  vector<int> answer;
  // for (auto it = v.rbegin(); it != v.rend(); ++it) {
  //   answer.push_back(*it);
  // }
  for (ptrdiff_t i = v.size()-1; i != -1; i--){
    answer.push_back(v[i]);
  }
  return answer;
}
