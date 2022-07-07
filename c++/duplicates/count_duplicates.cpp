/*
	 Count the number of Duplicates
	 Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

	 Example
	 "abcde" -> 0 # no characters repeats more than once
	 "aabbcde" -> 2 # 'a' and 'b'
	 "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
	 "indivisibility" -> 1 # 'i' occurs six times
	 "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
	 "aA11" -> 2 # 'a' and '1'
	 "ABBA" -> 2 # 'A' and 'B' each occur twice
	 */

#include <iostream>
#include <string>
#include <algorithm>

size_t duplicateCount(const char* in);

int main(void) {
	int answer = duplicateCount("Indivisibility");
	std::cout << "Ans: " << answer << std::endl;
}

size_t duplicateCount( const char* in ) {
	std::string s;
	for ( size_t i = 0; in[i] != '\0'; i++ ){
		s.push_back(in[i]);
	};
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::sort( s.begin(), s.end() );
	int count_igual{};
	bool igual = false;
	for ( size_t i = 1; i <= s.size(); i++ ) {
		if ( s[i] == s[i-1] and not igual ) {
			igual = true;
			count_igual++;
		}
		else if ( s[i] != s[i-1] ) {
			igual = false;
		};
	};
	return count_igual;
}

// Para estudiar:
