#include <cstdio>
#include <iostream>
using namespace std;
using std::string;

char * to_caps(char input){
	int counter = 0;
	static int caps[sizeof(input)];
	for(char value : input){
		if ( value > 90 ) {
			value = value - 32;
		}
		caps[counter] = value;
		counter++;
	}
	return caps;
}

int main () {
	char input[] = "aA5bcj3hhF";
	int *output;
	output = to_caps(input);
	printf("input: %s -- output: %s\n", input, output);
	return 0;
}

