// Time a loop. Write out the time in milliseconds. Do this for the default
// setting of your compiler and for a setting using an optimizer (e.g., −O2 or
// "release"). Be careful not to have the optimizer eliminate your whole loop as
// dead code because you did not use a result.

#include <iostream>
#include <chrono>
#include <valarray>

int main () {
  // We will square root a huge valarray.
  std::valarray<double> arr (18.2, 1e8);

  auto tbeg = std::chrono::high_resolution_clock::now();
  for (auto &el : arr) {
    el = sqrt(el);
    el = sqrt(el);
    el = sqrt(el);
    el = sqrt(el);
    el = sqrt(el);
  }
  auto tend = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(tend - tbeg)
          .count();
  std::cout << "Loop ran for " << duration << " ms." << std::endl;
}
