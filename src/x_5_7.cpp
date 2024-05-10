// Initialize a vector<int> with the elements 5, 9, −1, 200, and 0. Print it.
// Sort is, and print it again.

#include <vector>
#include <algorithm>
#include <iostream>

std::ostream& operator<< (std::ostream &os, const std::vector<int> &vec) {
  for (const auto &elem : vec) {
    os << elem << " ";
  }
  return os;
}

int main() {
  std::vector<int> vec{5, 9, -1, 200, 0}; // Vector initialization
  std::cout << vec << std::endl;          // Print it
  std::sort(vec.begin(), vec.end());
  std::cout << vec << std::endl;          // Print it again
}
