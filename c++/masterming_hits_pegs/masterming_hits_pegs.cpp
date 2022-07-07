/*
	 Mastermind
	 Mastermind is a two-player game where one player creates a four-color code from a possible six colors. The other player has ten turns to guess this code. After each guess, the "codemaker" places pegs corresponding to correct guesses and the "codebreaker" then guesses again, based on these pegs. Black pegs are given for every color in the guess that is correctly placed, and white pegs are given for other colors in the guess that are in the code, but were not guessed in the correct position.

	 More info: Mastermind.

	 Task
	 Your task is to implement a function that will compare the player's guess to the secret code and return an appropriate number of colored hints - one black peg for each correctly guessed color in a correct position, one white peg for each correct color in an incorrect position.

	 Specifics for this kata:
	 The number of colors in the code is random instead of always being 4
	 The number of possible colors has been increased
	 The same color may appear multiple times in different positions
Examples:
No elements match:
code   = [1, 2, 3]
guess  = [4, 5, 6]
result = {black: 0, white: 0}

2 elements match, both in wrong positions:
code   = [1, 2, 3]
guess  = [2, 1, 4]
result = {black: 0, white: 2}

3 elements match, one in correct position and two in wrong positions:
code   = [1, 2, 3]
guess  = [2, 1, 3]
result = {black: 1, white: 2}

3 elements match, one in correct position and two in wrong positions:
code   = [0, 0, 0, 1, 1]
guess  = [2, 2, 0, 0, 0]
result = {black: 1, white: 2}
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_hints(const std::vector<int> &answer, const std::vector<int> &guess);

int main(void){
	int ans = get_hints({8, 5, 8, 3, 7, 5, 7, 9, 8, 8, 0, 0, 3, 3, 6, 6, 6, 4, 4, 0, 7, 0, 6, 2, 7, 9, 8, 5, 9, 7, 4, 9, 5, 8, 6, 6, 5, 3, 5, 2, 1}, {8, 9, 8, 8, 7, 7, 0, 9, 2, 8, 0, 6, 3, 4, 9, 9, 7, 3, 4, 8, 2, 0, 8, 2, 6, 5, 8, 5, 0, 8, 6, 9, 5, 0, 6, 6, 5, 6, 5, 4, 1});
	return 0;
}

int get_hints(const std::vector<int> &answer, const std::vector<int> &guess) {
	int bp{}, t{};
	vector<int> a{answer}, g{guess};
	for (size_t j = 0; j < a.size(); j++) {
		for (size_t i = j; i < g.size(); i++) {
			if ( a[j] == g[i] && j == i ) bp++;
		};
	};
	for ( int nume = 0; nume < 10 ; nume++ ) {
		int ans = count(answer.begin(), answer.end(), nume);
		int gue = count(guess.begin(), guess.end(), nume);
		if ( ! (ans == 0 and gue == 0) ) {
			int minimo = min(gue, ans);
			t += minimo;
		}
	};
	cout << "\n\n" << endl;
	cout << "Black: " << bp << endl;
	cout << "Iguales: " << t << endl;
	cout << "White: " << t - bp << endl;
	return 0; // {black, white}
}
