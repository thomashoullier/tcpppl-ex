// Repeat §X.5[7] with a vector<string> initialized with "Kant", "Plato",
// "Aristotle", "Kierkegard", and"Hume".

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
std::ostream& operator<< (std::ostream &os, const std::vector<T> &vec) {
  for (const auto &elem : vec) {
    os << elem << " ";
  }
  return os;
}

int main() {
  std::vector<std::string>
    vec{"Kant", "Plato", "Aristotle", "Kierkegard", "Hume"};
  std::cout << vec << std::endl;          // Print it
  std::sort(vec.begin(), vec.end());
  std::cout << vec << std::endl;          // Print it again
}
