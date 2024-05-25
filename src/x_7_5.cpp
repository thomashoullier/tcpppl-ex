// For each declaration in §6.3, do the following: If the declaration is not a
// deﬁnition, write a deﬁnition for it. If the declaration is a deﬁnition, write
// a declaration for it that is not also a deﬁnition.

#include <iostream>
#include <string>
#include <vector>
#include <complex>

char ch;
std::string s;
auto count = 1;
const double pi{3.1415926535897};
extern int error_number;

const char *name = "Njal";
const char *season[] = {"spring", "summer", "fall", "winter"};
std::vector<std::string> people{name, "Skarphedin", "Gunnar"};

struct Date {
  int d, m, y;
};
int day(Date *p) { return p->d; }
double sqrt(double);
template <class T> T abs(T a) { return a < 0 ? -a : a; }

constexpr int fac(int n) { return (n < 2) ? 1 : n * fac(n - 1); }
constexpr double zz{3 * fac(7)};

using Cmplx = std::complex<double>;
struct User;
enum class Beer { Carlsberg, Tuborg, Thor };
namespace NS {int a;}

int main() {
  std::cout << "x_7_5" << std::endl;
  char ch_decl; // Uninitialized because it is not in the global scope.
  std::cout << "char ch; " << ch << ch_decl << std::endl;
  std::cout << "std::string s does not provide a way to be declared without"
               " also being defined." << std::endl;
  int count_decl; // Uninitialized because it is not in the global scope.
  std::cout << "auto count = 1; " << count << count_decl << std::endl;
  double pi_decl; // We cannot put const here in gcc.
  std::cout << "const double pi " << pi << pi_decl << std::endl;
  // We get a libc error when trying to print error_number, I don't know
  // exactly why.
  //std::cout << "extern int error_number: " << error_number << std::endl;

  const char *name_decl; // declaration.
  std::cout << "name: " << name << std::endl;
  const char *season_decl[4]; // declaration.
  std::cout << "season: " << season[0] << season_decl[0] << std::endl;
  std::cout << "There is no way to only declare std::vector<std::string>"
            << std::endl;
  }
