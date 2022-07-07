/*
	 Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until the top which will have a volume of 1^3.

	 You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

	 The parameter of the function findNb (find_nb, find-nb, findNb, ...) will be an integer m and you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m if such a n exists or -1 if there is no such n.

Examples:
findNb(1071225) --> 45

findNb(91716553919377) --> -1
*/


#include <iostream>

class ASum{
	public:
		static long long findNb(long long m) {
			long long sum{};
			for (long long i = 1; true ; i++) {
				sum += i*i*i;
				if ( sum == m ) {
					return i;
				};
				if ( sum > m ) {
					return -1;
				};
			};
		}
};


int main(int argc, char *argv[]) {
	ASum pile;
	static long long ans = pile.findNb(10);
	std::cout << "R: " << ans << std::endl;
	return 0;
}

