/*
	 1, 246, 2, 123, 3, 82, 6, 41 are the divisors of number 246. Squaring these divisors we get: 1, 60516, 4, 15129, 9, 6724, 36, 1681. The sum of these squares is 84100 which is 290 * 290.

	 Task
	 Find all integers between m and n (m and n integers with 1 <= m <= n) such that the sum of their squared divisors is itself a square.

	 We will return an array of subarrays or of tuples (in C an array of Pair) or a string. The subarrays (or tuples or Pairs) will have two elements: first the number the squared divisors of which is a square and then the sum of the squared divisors.

Example:
list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]
The form of the examples may change according to the language, see "Sample Tests".

Note
In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing whitespace: you can use dynamically allocated character strings.
*/

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;

class SumSquaredDivisors {

	public:
		static vector<pair<long long, long long>> listSquared(long long m, long long n) {
			long long sum{};
			pair<long long, long long> foo;
			vector<pair<long long, long long>> ans;
			for ( long long i{m}; i < n; i++) {
				for ( long long j{1}; j <= i; j++) {
					if ( i % j == 0 ) sum += j*j;
				};
				if ( sqrt(sum) - floor(sqrt(sum)) == 0 ) { // is integer?
					foo = make_pair(i, sum);
					ans.push_back(foo);
				};
				sum = 0; // sum back to zero
			};
			return ans;
		}
};

int main(int argc, char *argv[]) {
	SumSquaredDivisors SSD;
	cout << "\nNúmero" << " -- " << "Suma de los divisores\n" << endl;
	for( auto item : SSD.listSquared(1, 250) ) {
		cout << item.first << " -- " << item.second << endl;
	};
	return 0;
}
