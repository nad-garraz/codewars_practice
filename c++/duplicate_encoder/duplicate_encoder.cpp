/*
	 The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

	 Examples
	 "din"      =>  "((("
	 "recede"   =>  "()()()"
	 "Success"  =>  ")())())"
	 "(( @"     =>  "))(("
	 Notes
	 Assertion messages may be unclear about what they display in some languages. If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!
	 */


#include <string>
#include <algorithm>
#include <iostream>

using	namespace std;

std::string duplicate_encoder(const std::string& word);

int main(void) {
	string answer = duplicate_encoder("AAaabcda");
	cout << "Answer: " << answer << endl;
	return 0;
}

std::string duplicate_encoder(const std::string& word) {
	string a{""};
	string w = word;
	transform(w.begin(), w.end(), w.begin(), ::tolower);
	for ( size_t j = 0; j < w.size(); j++ ) {
		int rep = count(w.begin(), w.end(), w[j]);
		rep > 1 ? a.push_back(')') : a.push_back('(');
	};
	return a;
}


////Para estudiar:
/*#include <string>
#include <cctype>

std::string duplicate_encoder(const std::string& word){

		std::map<char, int> table;
		for(auto x : word) table[std::tolower(x)]++;

		std::string result;
		for(auto x: word) result += (table[std::tolower(x)]==1)? "(":")";

		return result;
}
*/
