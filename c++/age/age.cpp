#include <string>

int get_age(const std::string &she_said);

int main() {
  int age = get_age("5 years old");
  printf("%d\n", age);
};

int get_age(const std::string &she_said) { return she_said[0] - 48; }
