#include <string>

using namespace std;

string reverseString (string str );

int main () {
	string s {"Hola Manola"};
	for ( char item : reverseString(s)) {
		printf("%c", item);
	};
};

string reverseString (string str ){
	string rev_str{};
	for ( string::reverse_iterator ri = str.rbegin(); ri != str.rend(); ri++ ) {
		rev_str.push_back(*ri);
	};
	return rev_str ;
}
