// Open a ﬁle for writing (as an ofstream) and write a few hundred integers to
// it.

#include <iostream>
#include <fstream>

int main () {
  std::ofstream of {"integers.txt"};

  for (auto i = 0 ; i < 300 ; ++i) {
    of << i << ", ";
  }
  of << 300;

  std::cout << "DONE" << std::endl;
}
