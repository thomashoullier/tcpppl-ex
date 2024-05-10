// Redo §X .5 [5], storing several(name, age) pairs in a class. Doing the
// reading and writing using your own >> and << operators.

#include <iostream>
#include <vector>

typedef std::string Name;
typedef int Age;

struct AgeEntry {
  Name name;
  Age age;
};

std::ostream& operator<< (std::ostream& os, const AgeEntry& ae) {
  return os << "(" << ae.name << ", " << ae.age << ")";
}

/* Read (Bob, 90) into an AgeEntry. */
std::istream& operator>> (std::istream& is, AgeEntry& ae) {
  char c;
  if (is>>c && c == '(') {
    Name name;
    while (is.get(c) && c != ',')
      name += c;
    if (is.get(c) && c == ' ') {
      Age age {0};
      if (is>>age>>c && c == ')') {
        ae = {name, age};
        return is;
      }
    }
  }
  // The input has failed.
  is.setstate(std::ios_base::failbit); // This is not in the book, maybe there is a typo?
  return is;
}

/* Class holding the AgeEntry list */
class AgeBook {
  std::vector<AgeEntry> entries;
public:
  /* Get n entries from istream */
  void get_entries (std::istream& is, int n) {
    AgeEntry ae;
    int i = 0;
    while (i != n && is >> ae) { // Order matters here
      entries.push_back(ae);
      ++i;
    }
  }

  std::ostream& print_entries (std::ostream& os) const {
    for (const auto &ae : entries) {
      os << ae;
    }
    return os;
  }
};

std::ostream& operator<< (std::ostream& os, const AgeBook& age_book) {
  age_book.print_entries(os);
  return os;
}

int main() {
  AgeEntry ae {"Bob", 34};
  std::cout << ae << std::endl;

  AgeBook age_book;
  age_book.get_entries(std::cin, 2);
  std::cout << age_book << std::endl;
}
