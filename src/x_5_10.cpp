// Open the ﬁle of integers from §X.5[9] for reading (as an ifstream) and read
// it.

#include <iostream>
#include <fstream>
#include <vector>

int main () {
  std::vector<int> vec; // Reading integers into this vector.
  std::ifstream ifs {"integers.txt"};
  char c {','};
  for (int i; ifs >> i && c == ',' ;) {
    vec.push_back(i);
    ifs.get(c);
  }

  for (auto const &i : vec) {
    std::cout << i << " " << std::endl;
  }
}
