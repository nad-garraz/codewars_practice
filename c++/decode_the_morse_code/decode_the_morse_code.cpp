/*
	 Part of Series 1/3
	 This kata is part of a series on the Morse code. After you solve this kata, you may move to the next one.

	 In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.
	 The Morse code encodes every character as a sequence of "dots" and "dashes". For example, the letter A is coded as ·−, letter Q is coded as −−·−, and digit 1 is coded as ·−−−−. The Morse code is case-insensitive, traditionally capital letters are used. When the message is written in Morse code, a single space is used to separate the character codes and 3 spaces are used to separate words. For example, the message HEY JUDE in Morse code is ···· · −·−−   ·−−− ··− −·· ·.

NOTE: Extra spaces before or after the code have no meaning and should be ignored.

In addition to letters, digits and some punctuation, there are some special service codes, the most notorious of those is the international distress signal SOS (that was first issued by Titanic), that is coded as ···−−−···. These special codes are treated as single special characters, and usually are transmitted as separate words.

Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.

For example:

decodeMorse('.... . -.--   .--- ..- -.. .')
//should return "HEY JUDE"
NOTE: For coding purposes you have to use ASCII characters . and -, not Unicode characters.

The Morse code table is preloaded for you as a dictionary, feel free to use it:

Coffeescript/C++/Go/JavaScript/Julia/PHP/Python/Ruby/TypeScript: MORSE_CODE['.--']
C#: MorseCode.Get(".--") (returns string)
F#: MorseCode.get ".--" (returns string)
Elixir: @morse_codes variable (from use MorseCode.Constants). Ignore the unused variable warning for morse_codes because it's no longer used and kept only for old solutions.
Elm: MorseCodes.get : Dict String String
Haskell: morseCodes ! ".--" (Codes are in a Map String String)
Java: MorseCode.get(".--")
Kotlin: MorseCode[".--"] ?: "" or MorseCode.getOrDefault(".--", "")
Racket: morse-code (a hash table)
Rust: MORSE_CODE
Scala: morseCodes(".--")
Swift: MorseCode[".--"] ?? "" or MorseCode[".--", default: ""]
C: provides parallel arrays, i.e. morse[2] == "-.-" for ascii[2] == "C"
NASM: a table of pointers to the morsecodes, and a corresponding list of ascii symbols
All the test strings would contain valid Morse code, so you may skip checking for errors and exceptions. In C#, tests will fail if the solution code throws an exception, please keep that in mind. This is mostly because otherwise the engine would simply ignore the tests, resulting in a "valid" solution.

Good luck!

After you complete this kata, you may try yourself at Decode the Morse code, advanced.
*/

#include <iostream>
#include <string>
#include <string>
using namespace std;
std::string decodeMorse(std::string m) { //Para sacar los espacios. strip()
  while ( m[0] == ' ' or m[ m.size() - 1 ] == ' ' ) {
  ( m[0] == ' ' ) ? m.erase(0, 1) : m.erase(m.size()-1, 1);
};
  string ch = "", decoded = "";
  size_t s{}, c{};
  for ( size_t i{}; i < m.size(); i++  ) {
    s = m.find("   ", i);
    c = m.find(" ", i);
    if ( s == i ) {
      decoded += MORSE_CODE[ ch ] + " ";
      i += 2;
      ch = "";
      }
    else if ( c == i and s != c ) {
      decoded += MORSE_CODE[ ch ];
      ch = "";
    }
    else{
      ch += m[i];
    }
  };
     decoded += MORSE_CODE[ ch ];
     return decoded;
}


// Muy elegante. Bien usado el regex y los iterators. Recordar que el MORSE_CODE no funciona acá, era
// del editor de la página.

#include <regex>

const std::regex morse("([^\\s]+|\\s{3})");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;

  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;

  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it) {
    std::string str = it->str();
    decoded += str == "   " ? " " : MORSE_CODE[str];
  }

  return decoded;
}
