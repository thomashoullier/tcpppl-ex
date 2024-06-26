// Find 5 different C++ constructs for which the meaning is undeﬁned (§6.1).
// (∗1.5) Find 5 different C++ constructs for which the meaning is
// implementation-deﬁned (§6.1).

// The cppreference website lists some undefined behavior cases.
// https://en.cppreference.com/w/cpp/language/ub
// We can find an index of implementation-defined behavior in the C++
// standard working draft.

#include <cstddef>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <climits>
#include <cstdint>

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

/* UB3 */
std::size_t f(int x) {
  std::size_t a;
  if (x) a = 42;
  return a;
}

/* UB4 */
int f2 () {
  bool b = true;
  unsigned char* p = reinterpret_cast<unsigned char*>(&b);
  *p = 10;
  return b == 0;
}

/* UB5 */
int bar () {
  int* p = nullptr;
  return *p;
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

  std::cout << "# UB3: uninitialized scalar" << std::endl;
  std::cout << f(0) << std::endl;

  std::cout << "# UB4: invalid scalar" << std::endl;
  std::cout << f2() << std::endl;

  std::cout << "# UB5: Null pointer dereference" << std::endl;
  auto p = bar();
  // std::cout << p << std::endl; // segfaults

  std::cout << "# ID1: Type of std::size_t" << std::endl;
  std::size_t i;
  std::cout << typeid(i).name() << std::endl;

  std::cout << "# ID2: Number of bits in a char" << std::endl;
  std::cout << CHAR_BIT << std::endl;

  std::cout << "# ID3: Text of std::bad_alloc::what()" << std::endl;
  std::bad_alloc e;
  std::cout << e.what() << std::endl;

  std::cout << "# ID4: Size of a long int" << std::endl;
  long int li;
  std::cout << sizeof(li) << std::endl;

  std::cout << "$ ID5: Conversion of pointers to integer types" << std::endl;
  int v {45};
  int *pv {&v};
  std::cout << "Value " << *pv << " at address " << reinterpret_cast<uintptr_t>(pv) << std::endl;
}
