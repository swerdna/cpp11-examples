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

//---------Example 2: typename resolution----------//
using namespace std;

template<typename T>
void adl(T)
{
  cout << "T";
}

struct S
{
};

template<typename T>
void call_adl(T t)
{
  // The first call doesn't depend on the template parameter, so it can be
  // evaluated when seen
  adl(S());

  // This needs to be evaluated when the template param is present
  adl(t);
}

void adl(S)
{
  cout << "S";
}

int main()
{
    {
        std::cout << "Variable defined outside namespace, initialization, lookup with same namespace as declaration" << std::endl;
        std::cout << foobar::x;
        std::cout << '\n';
    }

    {
        // output: TS
        std::cout << "Typename resolution" << std::endl;
        call_adl(S());
        std::cout << '\n';
    }
}
