//We want to know the index of the vowels in a given word, for example, there are two vowels in the word super (the second and fourth letters).
//So given a string "super", we should return a list of [2, 4].
#include <vector>
#include <string>

//std::vector<int> vowelIndices(const std::string& word);
std::vector<int> vowelIndices(std::string word);

int main()
{
	std::vector<int> vec = vowelIndices("12abefYY");
	for (int item : vec) {
		printf("%d\n", item);
	}
	return 0;
};

//// Mi solución
/*std::vector<int> vowelIndices(const std::string& word) {
	std::vector<int> res;
	for ( int i = 0; i < word.length(); i++ ) {
	int letra = word[i];
	if (	letra < 91 and letra > 64 ) {
	letra = letra + 32;
	}
	switch (letra) {
	case 97:
	res.push_back(i+1); break;
	case 101:
	res.push_back(i+1); break;
	case 105:
	res.push_back(i+1); break;
	case 111:
	res.push_back(i+1); break;
	case 117:
	res.push_back(i+1); break;
	case 121:
	res.push_back(i+1); break;
	}
	}
	return res;
	}*/

// Solución para estudiar
std::vector<int> vowelIndices(std::string word) {
	std::vector<int> res;
	const std::string vowels {"aeiouyAEIOUY"};
	auto found = word.find_first_of(vowels);
	while(found!=std::string::npos) {
		++found;
		res.push_back(found);
		found = word.find_first_of(vowels, found);
		printf("%d\n", found);
	}
	return res;
}

