// Repeat the histogram drawing example from §5.6.3 for a normal_distribution
// and 30 rows.

#include <functional>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

const int n_rows = 30;

/* Draw n_values into the histogram. */
template <typename Generator>
std::vector<int> draw_values (int n_values, Generator& rnd) {
  std::vector<int> histogram(n_rows);
  for (auto i = 0; i < n_values; ++i) {
    // Perform the random drawing
    auto real_value = rnd();
    // Round to the nearest integer
    int int_value = std::round(real_value);
    // Clip to the histogram bins.
    int clamped_value = std::clamp(int_value, 0, n_rows-1);
    ++histogram.at(clamped_value);
  }
  return histogram;
}

void plot_histogram(const std::vector<int> histogram) {
  int index = 0;
  for (const auto &count : histogram) {
    std::cout << index << "\t";
    for (int i = 0 ; i < count ; ++i) std::cout << '*';
    std::cout << std::endl;
    ++index;
  }
}

int main() {
  auto rnd = std::bind(std::normal_distribution<double>{15, 4},
                       std::default_random_engine{});
  auto histogram = draw_values(800, rnd);
  plot_histogram(histogram);
}
