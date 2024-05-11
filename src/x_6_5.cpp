// Use a regex to find all decimal numbers in a file.

#include <fstream>
#include <iostream>
#include <regex>

int main() {

  std::regex pat(R"(\d+)"); // Digits pattern.

  // A file x_6_5.txt must be next to the executable.
  std::ifstream input_file{"x_6_5.txt"};

  for (std::string line ; getline(input_file, line) ; ) {
    std::sregex_iterator matches(line.begin(), line.end(), pat);
    while (matches != std::sregex_iterator {}) {
      std::cout << matches->str() << " ";
      matches++;
    }
    std::cout << std::endl;
  }
}
