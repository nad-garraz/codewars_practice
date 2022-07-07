/*
	 For encrypting strings this region of chars is given (in this order!):

	 all letters (ascending, first all UpperCase, then all LowerCase)
	 all digits (ascending)
	 the following chars: .,:;-?! '()$%&"
	 These are 77 chars! (This region is zero-based.)

	 Write two methods:

	 std::string encrypt(std::string text)
	 std::string decrypt(std::string text)
Prechecks:

If the input-string has chars, that are not in the region, throw an Exception(C#, Python) or Error(JavaScript).
If the input-string is null or empty return exactly this value!
For building the encrypted string:

For every second char do a switch of the case.
For every char take the index from the region. Take the difference from the region-index of the char before (from the input text! Not from the fresh encrypted char before!). (Char2 = Char1-Char2)
Replace the original char by the char of the difference-value from the region. In this step the first letter of the text is unchanged.
Replace the first char by the mirror in the given region. ('A' -> '"', 'B' -> '&', ...)
Simple example:

Input: "Business"
Step 1: "BUsInEsS"
Step 2: "B61kujla"
B -> U
B (1) - U (20) = -19
-19 + 77 = 58
Region[58] = "6"
U -> s
U (20) - s (44) = -24
-24 + 77 = 53
Region[53] = "1"
Step 3: "&61kujla"
This kata is part of the Simple Encryption Series:
Simple Encryption #1 - Alternating Split
Simple Encryption #2- Index-Difference
Simple Encryption #3 - Turn The Bits Around
Simple Encryption #4 - Qwerty

Have fun coding it and please don't forget to vote and rank this kata! :-)
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string d = "abcdefghijklmnopqrstuvwxyz";
string num = "0123456789";
string s = ".,:;-?! '()$%&\"";
string chars = u + d + num + s;
map<char, int> char_int;
map<int, char> int_char;

class Kata{
	public:
		std::string encrypt(std::string text) {
			if (	text.empty() ) return text;
			//throw std::runtime_error{ "I'd be glad to make an exception." };
			string answer{text};
			for ( size_t i{}; i < chars.size(); i++ ) {
				char_int[chars[i]] = i; // populate map
				int_char[i] = chars[i];	// populate map
			}
			for ( size_t i = 1; i < text.size(); i++ ) {
				if ( i % 2 == 1 and s.find_first_of(text[i]) == string::npos ) {
					text[i] = toupper(text[i]);
				}
				int a = char_int.find(text[i-1]) -> second;
				int b = char_int.find(text[i]) -> second;
				int c = a - b;
				if ( c < 0 ) {
					c += 77;
					//cout << "sumé en: " << i << endl;
				}
				answer[i] = (int_char.find(c))->second;
			};
			answer[0] = chars[76 - chars.find(text[0])];
			return answer;
		}

		std::string decrypt(std::string encryptedText) {
			if (encryptedText.empty() ) return encryptedText;

			encryptedText[0] = chars[76 - chars.find(encryptedText[0])];
			for ( size_t i = 1 ; i < encryptedText.size();  i++ ) {
				int a = char_int.find(encryptedText[i-1]) -> second;
				int b = char_int.find(encryptedText[i]) -> second;
				int c = a - b + 77;
				if ( c >= 77 ) c -= 77;
				encryptedText[i] = int_char.find(c) -> second;
			}
			// to lowercase
			for ( size_t i = 1 ; i < encryptedText.size();  i++ ) {
				if ( i % 2 == 1 ) {
				encryptedText[i] = tolower(encryptedText[i]);
				}
			};
			return encryptedText;
		}
};

int main(int argc, char *argv[]) {
	Kata Enc{};
	cout << Enc.encrypt("Do the kata \"Kobayashi-Maru-Test!\" Endless fun and excitement when finding a solution!") << endl;
	cout << Enc.decrypt("$-Wy,dM79H'i'o$n0C&I.ZTcMJw5vPlZc Hn!krhlaa:khV mkL;gvtP-S7Rt1Vp2RV:wV9VuhO Iz3dqb.U0w") << endl;
	return 0;
}
