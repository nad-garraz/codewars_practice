#include <vector>
#include <cstdio>

bool betterThanAverage(std::vector<int> classPoints, int yourPoints);

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {
	int total{};
	int size = classPoints.size();
	for( int item : classPoints) {
		total += item;
	};
	return (yourPoints * size) > total;
}



int main () {
	std::vector<int> vec {4, 8, 3};
	bool ans = betterThanAverage(vec, 3);
	if ( ! ans)  {
		printf("false\n");
	}
	else {
		printf("true\n");
	};

	return 0;
};

