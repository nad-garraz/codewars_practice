#include <cstdio>
#include <vector>
/*Given an array of integers.*/

/*Return an array, where the first element is the count of positives numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.*/

/*If the input is an empty array or is null, return an empty array.*/

/*Example*/
/*For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].*/

std::vector<int> countPositivesSumNegatives(std::vector<int> input);

int main(int argc, char *argv[])
{
	std::vector<int> input = {-2, -4, 5, 1, 2, -2, 0, 0, 0};
	std::vector<int> output = countPositivesSumNegatives(input);
	printf("neg: %d, pos: %d\n", output[0], output[1]);
	printf("%d", -4%3);
	return 0;
}


std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
	int pos = 0;
	int neg = 0;
	std::vector<int> nulo;
	if (input.size() != 0 ) {
	for (int item : input) {
		item <= 0 ? neg += item : pos++;
	}
		std::vector<int> result = {neg, pos};
		return result;
	} else {
	return nulo;
	}
}
