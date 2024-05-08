// Read in a bool, a char, an int, a double, and a string.

#include <iostream>

int main() {
  std::cout << "Type a bool... ";
  bool a {true};
  std::cin >> a;
  std::cout << a << std::endl;

  std::cout << "Type a char... ";
  char b {'z'};
  std::cin >> b;
  std::cout << b << std::endl;

  std::cout << "Type an int... ";
  int c {0};
  std::cin >> c;
  std::cout << c << std::endl;

  std::cout << "Type a double... ";
  double d {0.0};
  std::cin >> d;
  std::cout << d << std::endl;

  std::cout << "Type a string... ";
  std::string s {""};
  std::cin >> s;
  std::cout << s << std::endl;
}
