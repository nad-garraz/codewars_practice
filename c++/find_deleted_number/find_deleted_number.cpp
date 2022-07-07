/*An ordered sequence of numbers from 1 to N is given. One number might have deleted from it, then the remaining numbers were mixed. Find the number that was deleted.

Example:

The starting array sequence is [1,2,3,4,5,6,7,8,9]
The mixed array with one deleted number is [3,2,4,6,7,8,1,9]
Your function should return the int 5.
If no number was deleted from the starting array, your function should return the int 0.

Note: N may be 1 or less (in the latter case, the first array will be []).
*/

#include <cstdio>
#include <list>
#include <iostream>

using namespace std;

int findDeletedNumber(list<int> startingList, list<int> mixedList);

int main(int argc, char *argv[])
{
	list<int> a{1,2,3,4,5,6,7,8,9};
	list<int> b{1,2,4,7,5,6,8,3,9};
	int c = findDeletedNumber(a, b);
	printf("%d", c);
}

int findDeletedNumber(list<int> startingList, list<int> mixedList) {
	for (int item : mixedList) {
		startingList.remove(item);
	};
	return startingList.front();
	//return startingList.empty() ? 0 : startingList.front();
}

// Para estudiar:
/*
#include <numeric>
using namespace std;
int findDeletedNumber(list<int> startingList, list<int> mixedList)
{
    int sumStarting = std::accumulate(startingList.begin(), startingList.end(), 0);
    int sumMixed = std::accumulate(mixedList.begin(), mixedList.end(), 0);
    return sumStarting - sumMixed;
}
*/
