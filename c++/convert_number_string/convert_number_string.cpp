/*
	 We need a function that can transform a number into a string.

	 What ways of achieving this do you know?

Examples:
123 --> "123"
999 --> "999"
*/


#include <iostream>
#include <string>

using namespace std;

std::string number_to_string(int num);

int main(int argc, char *argv[]) {
	cout << number_to_string(12304) + " <- esto es un string";
	return 0;
}


// La fácil
/*
	 std::string number_to_string(int num) {
	 return std::to_string(num);
	 }
	 */


// La que se hace a mano

std::string number_to_string(int num) {
	string str = {""};
	while ( num ) {
		char a = num % 10 + 48; // le sumo para que se el character numérico
		num = num /10; // Achico el número truncando el último número del "int"
		str += a;
	}
	string ans{""};
	for (auto	 it = str.rbegin(); it != str.rend(); it++) {
		ans += *it;
	};
	return ans;
}
