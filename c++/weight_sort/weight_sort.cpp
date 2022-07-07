/*
	 My friend John and I are members of the "Fat to Fit Club (FFC)". John is worried because each month a list with the weights of members is published and each month he is the last on the list which means he is the heaviest.

	 I am the one who establishes the list so I told him: "Don't worry any more, I will modify the order of the list". It was decided to attribute a "weight" to numbers. The weight of a number will be from now on the sum of its digits.

	 For example 99 will have "weight" 18, 100 will have "weight" 1 so in the list 100 will come before 99.

	 Given a string with the weights of FFC members in normal order can you give this string ordered by "weights" of these numbers?

Example:
"56 65 74 100 99 68 86 180 90" ordered by numbers weights becomes:

"100 180 90 56 65 74 68 86 99"
When two numbers have the same "weight", let us class them as if they were strings (alphabetical ordering) and not numbers:

180 is before 90 since, having the same "weight" (9), it comes before as a string.

All numbers in the list are positive numbers and the list can be empty.

Notes
it may happen that the input string have leading, trailing whitespaces and more than a unique whitespace between two consecutive numbers
For C: The result is freed.
*/


#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <utility>
//#include "../templates/templates.h"


//using namespace std;

template <typename T>
inline void swap(T &x, T &y) {
	T temp = std::move(x);
	x = std::move(y);
	y = std::move(temp);
};

class WeightSort {
	public:
		static std::string orderWeight(const std::string &s){
			std::vector<std::pair<std::string, int>> v;
			std::string ans;
			std::pair<std::string, int> temp {};
			std::regex nums("[0-9]+");
			for (auto it = std::sregex_iterator(s.begin(), s.end(), nums); it!= std::sregex_iterator(); ++it){
				int sum{};
				for ( char x : it->str() ) sum += x - 48; // sum individual digits of input
				v.push_back(std::make_pair(it->str(), sum));
			}
			for ( size_t i{}; i < v.size(); i++ ) {
				for ( size_t j = 0; j < i; j++ ) {
					if ( v[i].second < v[j].second ) {
						swap(v[i], v[j]);
					}
					else if ( v[i].second == v[j].second and v[i].first < v[j].first ) {
						swap(v[i], v[j]);
					};
				};
			};
			for (auto it{v.begin()}; it != v.end(); it++) { // Make answer
				ans += it->first;
				if ( std::next(it) != v.end() ) ans += " ";
			};
			return ans;
		}
};

int main(int argc, char *argv[]) {
	WeightSort ws;
	std::cout << ws.orderWeight("387087 210 176 351832 100 430372 8 58052 54 175432 120 269974 147 309754 91 404858 67 271476 164 295747 111 102 40");
	return 0;
}


