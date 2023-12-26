/*
Define a method/function that removes from a given array of integers all the values contained in a second array.

Examples (input -> output):
* [1, 1, 2, 3, 1, 2, 3, 4], [1, 3] -> [2, 2, 4]
* [1, 1, 2, 3, 1, 2, 3, 4, 4, 3, 5, 6, 7, 2, 8], [1, 3, 4, 2] -> [5, 6, 7, 8]
* [8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2, 3], [2, 4, 3] -> [8, 7, 6, 5, 1]
Enjoy it!!
*/



#include <iostream>
#include <vector>


using namespace std;

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values);

int main(int argc, char *argv[]) {
  for (auto items : remove_values({1,4,5,6}, {5})){
  cout << items << ' ';
  }
  cout << endl;
	return 0;
}

vector<int> remove_values(vector<int> integers, vector<int> values) {
  bool add = true;
  vector<int> answer {};

  for( auto item : integers ){
    for ( auto value : values ){
      if ( value == item ) {
        add = false;
        break;
      }
    } 
    if (add) answer.push_back(item);
    add = true;
  }
  return answer;
}
