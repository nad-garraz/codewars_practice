#include <cstdio>
#include <string>


int string_to_number(const std::string& s);
//int string_to_number2(const std::string& s);

int main(int argc, char *argv[])
{
	std::string	s = "-123456";
	char* s_ptr = &s[0];
	int size = s.size();
	int a = string_to_number(s);

	printf("String: %s, Int: %d\n", s_ptr, a);
	return 0;
}


/******************************************************************************
 * Description: Se supone que esta función transformaría un string 123 en un int 123
 * No se me ocurre que mierda hacer.... salió esa mierda
 *****************************************************************************/
// int string_to_number(const std::string& s){
// 	size_t size = s.size();
// 	int n[size]{};
// 	//int numero = 0;
// 	int suma = 0;
//
// 	for (int i = 0; i < size; i++ ){
// 		for (int j = 0; j < size ; j++ ){
// 			if (n[j] != 45){
// 				n[j] = n[j] * 10;
// 			}
// 		}
// 		if (s[i] != 45) {
// 			n[i] = s[i] - 48;
// 		} else{
// 			n[i] = s[i];
// 		}
// 	}
// 	if (s[0] != 45 ) {
// 		for (int i=0; i < size; i++) {
// 			suma += n[i];
// 		}
// 	}else{
// 		for (int i=1; i < size; i++) {
// 			suma += n[i];
// 		}
// 			suma = suma * -1;
// 	}
// 	return suma;
// }

int string_to_number2(const std::string& s)
{
	int size = s.size();
	int n
	int n[size] = {0};
	for (int i = 0; i < size; i++){
		n[i] = ( s[i] - 48 ) * 10;
	}
}
