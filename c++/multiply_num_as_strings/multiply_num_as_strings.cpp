/*
DESCRIPTION:
This is the first part. You can solve the second part here
(https://www.codewars.com/kata/multiplying-numbers-as-strings-part-ii/javascript)
when you are done with this. Multiply two numbers! Simple!

1 The arguments are passed as strings.
2 The numbers may be way very large
3 Answer should be returned as a string
4 The returned "number" should not start with zeros e.g. 0123 is invalid

Note: 100 randomly generated tests!
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b);
void reverse_string(string &str_in);
string sum_vector_of_strings();
void add_zeroes(string &str, int zeroes);
void remove_front_zeroes(string &str);


int main(void) {
  cout << multiply("03", "0002") << endl;
  return 0;
}

void reverse_string(string &str) {
  size_t n = str.length();
  for (size_t i{}; i < n / 2; i++)
    swap(str[i], str[n - 1 - i]);
}

// Adds zeroes to the end of a type string number
void add_zeroes(string &str, int zeroes) {
  for (int i{}; i < zeroes; i++)
    str += "0";
}

// Remove unnecesary zeroes from the front of 
// the tpre string number
void remove_front_zeroes(string &str) {
  for (auto it{str.begin()}; it != str.end(); it++) {
    if (*it == '0') {
      str.erase(it);
      it--;
    } else {
      break;
    }
  }
}

// Takes a vector with type string numbers and adds
// them returning a string with the result
string sum_vector_of_strings(vector<string> v) {
  int order{1}, number{}, r{}, l{};
  string sum{""};
  int l_last_item =
      v[v.size() - 1].size();      // size of the last string of the vector
  while (order <= l_last_item) {   // cycle trough the digits to the number
    for (auto string_number : v) { // cycle trough the numbers of the vector
      l = string_number.size();
      if (order <= l)
        number += string_number[l - order] - '0';
    }
    r = number / 10; // all digits except the last one of the number
    sum += to_string(number % 10); // sum only last digit
    order++;
    number = r;
  }
  sum += (r == 0) ? "" : to_string(r);
  reverse_string(sum);
  return sum;
};

string multiply(string a, string b) {
  if (a == "0" or b == "0"){
    return "0";
  } else {
  remove_front_zeroes(a);
  remove_front_zeroes(b);
  }

  if (a.length() < 12 and b.length() < 12)
    return to_string(stoull(a) * stoull(b));
  // Short numbers

  vector<int> number_expand{};
  vector<string> number_after_expand{};
  string sum{""}, suma{""};
  int last_digit{}, r{}, zeroes{};
  // Looping backwards
  for (string::reverse_iterator rit_a{a.rbegin()}; rit_a != a.rend(); rit_a++) {
    number_expand.erase(number_expand.begin(), number_expand.end());
    for (string::reverse_iterator rit_b{b.rbegin()}; rit_b != b.rend(); rit_b++)
      number_expand.push_back((*rit_a - '0') * (*rit_b - '0'));
    for (auto num : number_expand) {
      last_digit = (num + r) % 10;
      sum += to_string(last_digit);
      r = (num + r) / 10;
    }
    sum += (r == 0) ? "" : to_string(r); // sum last "remainder" after loop
    reverse_string(sum);
    add_zeroes(sum, zeroes); // zeroes = digits in "string a" from 0 ...
    cout << zeroes << endl;
    number_after_expand.push_back(sum);
    sum = "";
    r = 0;
    last_digit = 0;
    zeroes++;
  }
  return sum_vector_of_strings(number_after_expand);
}
