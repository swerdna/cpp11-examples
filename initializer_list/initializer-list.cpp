#include <iostream>
#include <initializer_list>

struct A {
  A() { std::cout << "1"; }

  A(int) { std::cout << "2"; }

  A(std::initializer_list<int>) { std::cout << "3"; }
};

int main(int argc, char *argv[]) {
  std::cout << "Initializer lists\n";
  std::cout << "Prints 1 if A() is called.  Prints 2 if A(int) is called, Prints 3 if A(std::initializer_list<int>) is called\n";

  // default constructor
  std::cout << "A a1;   = " ; A a1 ; std::cout << '\n';
  // initializer list, but it's empty, default constructor defined, so that's used
  std::cout << "A a2{};   = " ; A a2{} ; std::cout << '\n';

  // init list
  std::cout << "A a3{ 1 };   = " ; A a3{ 1 } ; std::cout << '\n';

  // init list
  std::cout << "A a4{ 1, 2 };   = " ; A a4{ 1, 2 } ; std::cout << '\n';
}

