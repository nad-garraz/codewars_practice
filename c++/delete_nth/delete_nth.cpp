/*
	 Enough is enough!
	 Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, since the motive usually repeats. He isn't fond of seeing the Eiffel tower 40 times. He tells them that he will only sit during the session if they show the same motive at most N times. Luckily, Alice and Bob are able to encode the motive as a number. Can you help them to remove numbers such that their list contains each number only up to N times, without changing the order?

	 Task
	 Given a list and a number, create a new list that contains each number of lst at most N times without reordering. For example if the input number is 2, and the input list is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3]. With list [20,37,20,21] and number 1, the result would be [20,37,21].
	 */

#include <iostream>
#include <vector>

using namespace std;


std::vector<int> deleteNth(std::vector<int> arr, int n);
int main(void) {
	std::vector<int> answer = deleteNth({1,2,1,1,1,1,1,1,1,3,3,3,3,3}, 3);
	for (int num : answer) {
		std::cout << num << " ";
	};
	return 0;
}

// version presentada
/*
std::vector<int> deleteNth(std::vector<int> arr, int n) {
	if ( arr.empty() ) return {};
	vector<int> ans = {arr[0]};
	for (size_t j = 1; j < arr.size(); j++) {
		int rep{};
		for (size_t i = 0; i <= j; i++) {
			if ( arr[j] == arr[i] ) rep++;
		};
		if ( rep <= n ) ans.push_back(arr[j]);
	}
	return ans;
}
*/

//version con pointers

std::vector<int> deleteNth(std::vector<int> arr, int n) {
	if ( arr.empty() ) return {};
	for (vector<int>::iterator j = next(arr.begin()); j < arr.end(); j++) {
		int rep = 0;
		for (vector<int>::iterator i = arr.begin(); i <= j; i++) {
			if ( *j == *i ) rep++;
		};
		if ( rep > n ) {
			cout << "Borré: " << *j << ", en: " << j - arr.begin() << endl;
			arr.erase(j);
			j = prev(j); // Atraso el iterator porque si no, se saltea un elemento.
		}
	}
	return arr;
}

