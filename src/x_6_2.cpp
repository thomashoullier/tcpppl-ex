// Write a program with two treads: one that writes hello every second and one
// that writes world !every second.

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

class ParallelPrinter {
  std::mutex m; // Mutex on the output stream.
  int count; // Count of number of prints.
  std::ostream &os;

public:
  ParallelPrinter (std::ostream &_os) : os{_os} {}

  void print_hello () {
    while (count < 10) {
      std::unique_lock<std::mutex> lck {m};
      os << "hello" << std::endl;
      ++count;
      lck.unlock();
      std::this_thread::sleep_for(std::chrono::seconds{1});
    }
  }

  void print_world() {
    while (count < 10) {
      std::unique_lock<std::mutex> lck{m};
      os << "world!" << std::endl;
      ++count;
      lck.unlock();
      std::this_thread::sleep_for(std::chrono::seconds{1});
    }
  }

  /* Print using both methods in parallel. */
  void print () {
    count = 0;
    std::thread t1{&ParallelPrinter::print_hello, this};
    std::thread t2{&ParallelPrinter::print_world, this};
    t1.join();
    t2.join();
  }
};

int main () {
  std::cout << "CTRL-C to interrupt." << std::endl;
  ParallelPrinter pprint {std::cout};
  pprint.print();
}
