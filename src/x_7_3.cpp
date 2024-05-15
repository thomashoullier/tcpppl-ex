// Find 5 different C++ constructs for which the meaning is undeﬁned (§6.1).
// (∗1.5) Find 5 different C++ constructs for which the meaning is
// implementation-deﬁned (§6.1).

// The cppreference website lists some undefined behavior cases.
// https://en.cppreference.com/w/cpp/language/ub

#include <iostream>
#include <limits>

/* UB1 */
int foo(int x) {
  return x + 1 > x; // either true or UB due to signed overflow
}

/* UB2 */
static int table[4] = {};
bool exists_in_table(int v)
{
    // return true in one of the first 4 iterations or UB due to out-of-bounds
    // access
  for (int i = 0; i <= 4; i++) {
    //std::cout << table[i] << std::endl;
    if (table[i] == v) {
      return true;
    }
  }
  return false;
}

int main () {
  std::cout << "# UB1: signed overflow comparison" << std::endl;
  if (std::numeric_limits<int>::is_signed) {
    std::cout << "ints are signed here" << std::endl;
    int max_int = std::numeric_limits<int>::max();
    std::cout << "max_int is: " << max_int << std::endl;
    std::cout << "max int + 1 is: " << max_int + 1 << std::endl;
    std::cout << "max_int + 1 > max_int is: " << foo(max_int) << std::endl;
  }

  std::cout << "# UB2: access out of bounds" << std::endl;
  std::cout << exists_in_table(145) << std::endl;
}