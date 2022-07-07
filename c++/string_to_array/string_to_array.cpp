/*
	 Write a function to split a string and convert it into an array of words.

	 Examples (Input -> Output):
 * "Robin Singh" ==> ["Robin", "Singh"]

 * "I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> string_to_array(const string& s);

int main(){
	vector<string> arr = string_to_array("I love arrays they are my favorite");
	for ( auto item : arr ) {
		cout << item << endl;
	};
	return 0;
};

vector<string> string_to_array(const string& s) {
	string word = "";
	vector<string> ans;
	for( int j = 0; j < s.size(); j++ ) {
		if ( s[j] != ' ' ) {
			word.push_back(s[j]);
		}
		else {
			ans.push_back(word);
			word = "";
		};
	}
		ans.push_back(word);
	return ans;
}
