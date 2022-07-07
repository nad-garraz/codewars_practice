#include <string>
#include <iostream>

using namespace std;

int getCount(const string& inputStr){
	int num_vowels{};
	int found = inputStr.find_first_of("aeiou");
	if (found != -1) num_vowels++;
	do {
		found = inputStr.find_first_of("aeiou", found + 1);
		//if (found == -1) break;
		num_vowels++;
	} while ( found != std::string::npos );
	return num_vowels;
}

int main() {
	int num_vowels = getCount("a");
	printf("%d\n", num_vowels);
};

