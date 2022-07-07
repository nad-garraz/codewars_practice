/*Given a string of words, you need to find the highest scoring word.

	Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

	You need to return the highest scoring word as a string.

	If two words score the same, return the word that appears earliest in the original string.

	All letters will be lowercase and all inputs will be valid.
	*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

std::string highestScoringWord(const std::string &str);

int main(void)
{
	std::string ans = highestScoringWord("what time are we climbing up the volcano");
	cout << ans;
};

std::string highestScoringWord(const std::string &str){
	std::string s = str + " ";
	std::vector<string> vec;
	std::string d = " ";
	size_t suma{}, maximo{}, j{}, elemento{}, last{}, next{};

	while ( ( next = s.find(d, last)) != std::string::npos ) {
		std::string palabra = s.substr(last, next - last);
		last = next + 1;
		vec.push_back(palabra);
		for (size_t i = 0; i < palabra.length(); i++ ) {
			suma += palabra[i];
		};
		if ( suma > maximo ) {
			maximo = suma;
			elemento = j;
		};
		j++;
		suma = 0;
	} ;
	return vec[elemento];
};


// Para estudiar:
/*
#include <string>

std::string highestScoringWord(const std::string &str)
{
  std::cout << str << std::endl;

  std::istringstream stm(str);
  std::string token, maxString;
  long maxValue = 0;

  auto GetValue = [](const std::string& s)
  {
    long r = 0;
    for (auto c : s)
      r += int(c) - int('a') + 1;

    return r;
  };

  while (std::getline(stm, token, ' '))
  {
    long actValue = GetValue(token);
    if (actValue > maxValue)
    {
      maxValue = actValue;
      maxString = token;
    }
  }

  return maxString;
}
*/
