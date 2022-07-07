#include <string>

using namespace std;

std::string fakeBin(std::string str);

std::string fakeBin(std::string str){
	char* str_ptr = &str[0];
	for ( size_t i{}; *(str_ptr+i) != 0; i++ ) {
		*(str_ptr+i) > 52 ? str[i] = 49 : str[i] = 48;
	};
  return str;
}

int main(int argc, char *argv[]) {
	std::string str = fakeBin("1234567890");
	for (char digit : str ) {
		printf("%c", digit);
	};
	return 0;
}

