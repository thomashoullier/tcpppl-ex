// Write out a bool, a char, an int, a double, and a string.

#include <iostream>

int main () {
  bool a {true};
  std::cout << "A bool: " << a << std::endl;

  char b {'g'};
  std::cout << "A char: " << b << std::endl;

  int c {2};
  std::cout << "An int: " << c << std::endl;

  double d {4.2};
  std::cout << "A double " << d << std::endl;

  std::string s {"STRING"};
  std::cout << "A string: " << s << std::endl;
}
