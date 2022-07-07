/*
	 Given an array of integers, find the one that appears an odd number of times.

	 There will always be only one integer that appears an odd number of times.

	 Examples
	 [7] should return 7, because it occurs 1 time (which is odd).
	 [0] should return 0, because it occurs 1 time (which is odd).
	 [1,1,2] should return 2, because it occurs 1 time (which is odd).
	 [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
	 [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
	 */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findOdd(const std::vector<int>& numbers);

int main(int argc, char *argv[]) {
	cout << findOdd({20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5});
	return 0;
}

int findOdd(const std::vector<int>& n){
	for (auto i : n )
		if (count(n.begin(), n.end(), i) % 2) return i;
	return 0;
}
