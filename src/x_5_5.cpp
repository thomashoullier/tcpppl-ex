// Write a program that reads a name (a string) and an age (an int) from the
// standard input stream cin. Then output a message including the name and age
// to the standard output stream cout.

#include <iostream>

int main () {
  std::string name;
  int age;
  std::cin >> name >> age;
  std::cout << "Your name is: " << name << std::endl
            << "Your age is: " << age << std::endl;
}
