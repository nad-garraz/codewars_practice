/*
Here you have to do some mathematical operations on a "dirty string". This kata checks some basics, it's not too difficult.

So what to do?

Input: String which consists of two positive numbers (doubles) and exactly one operator like +, -, * or / always between these numbers. The string is dirty, which means that there are different characters inside too, not only numbers and the operator. You have to combine all digits left and right, perhaps with "." inside (doubles), and to calculate the result which has to be rounded to an integer and converted to a string at the end.

Easy example:
Input: "gdfgdf234dg54gf*23oP42"
Output: "54929268" (because 23454*2342=54929268)
First there are some static tests, later on random tests too...

Hope you have fun! :-)
*/



#include <iostream>
#include <string>
#include <math.h>

using namespace std;

std::string calculateString(std::string calcIt);

int main(int argc, char *argv[]) {
	//Captar los numeros con find ["123456789"]
cout << calculateString(";$%§fsdfsd235??df/sdfgf5gh.000kk0000") << endl;
	return 0;
}
string calculateString(std::string calcIt) {
    string str{""}, str1 = "", str2 = "", operators = "+-*/", numbers = "0123456789.-";
    double num{};
    size_t found = calcIt.find_first_of(numbers, 0);
    while ( found != string::npos )
    {
        str += calcIt[found];
        found = calcIt.find_first_of("0123456789.*+-/", found + 1);
    }
    found = str.find_first_of(operators, 0);
    str1 = str.substr(0, found);
    str2 = str.substr(found + 1);

    char op = str[found];
    double a = stod(str1);
    double b = stod(str2);
    switch (op)
    {
        case ('+'): { num = a + b; break;};
        case ('-'): { num = a - b; break;};
        case ('*'): { num = a * b; break;};
        case ('/'): { num = a / b; break;};
    }
    string result = to_string(round(num));
    result.erase(result.find('.', 0));
    return  result;
}

