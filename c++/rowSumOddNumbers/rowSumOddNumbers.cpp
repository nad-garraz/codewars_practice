#include <cstdio>


long long rowSumOddNumbers(unsigned n);

long long rowSumOddNumbers(unsigned n){
	unsigned	int first_odd = (n) * (n-1) + 1;
	unsigned	int ans{};
	for (unsigned i = 0; i < n; i++) {
		ans += first_odd + 2*i;
	};
	return ans;
}


int main () {
	printf("%lld\n", rowSumOddNumbers(3));
	return rowSumOddNumbers(5);
};

