#include <string>

unsigned int strCount(std::string word, char letter){
  unsigned int a{};
  int found = word.find_first_of(letter);
  while ( found != std::string::npos ) {
    found = word.find_first_of(letter, found + 1);
    a++;
  }
  return a;

//############# Solución para estudiar
//
//#include <string>

//unsigned int strCount(std::string word, char letter){
  //return count(word.begin(), word.end(), letter);
//}
