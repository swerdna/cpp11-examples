#include<iostream>

int foo()
{
  return 10;
}

struct foobar
{
  static int x;
  static int foo()
  {
    return 11;
  }
};

// foo() will be looked-up as if it's defined inline in struct foobar.
// "Looked up as if the definition of the member occured in that namespace"
int foobar::x = foo();

int main()
{
    std::cout << "Variable defined outside namespace, initialization, lookup with same namespace as declaration" << std::endl;
    std::cout << foobar::x;
}
