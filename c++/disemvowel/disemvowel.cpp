/*
	 Trolls are attacking your comment section!

	 A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.

	 Your task is to write a function that takes a string and return a new string with all vowels removed.

	 For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".

Note: for this kata y isn't considered a vowel.
*/



#include <iostream>
#include <string>

using namespace std;


std::string disemvowel(const std::string& str);

int main(int argc, char *argv[]) {

	cout << disemvowel("yo mama") << endl;

	return 0;
}

std::string disemvowel(const std::string& str) {
	string answer = str;
	auto found = answer.find_first_of("aeiouAEIOU");
	while ( found != string::npos ) {
		answer.erase(answer.begin() + found);
		found = answer.find_first_of("aeiouAEIOU");
	};
	return answer;
}

// Lindo y compacto
/*
# include <string>
std::string disemvowel(std::string str) {
  std::string vowels = "AEIOUaeiou", result = "";

  for (auto& ch : str)
    if (vowels.find(ch) == std::string::npos)
      result += ch;

  return result;
}
*/

// Mas compacto con regex
/*
# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}*/
