#include "misc_examples.h"

#include <iostream>
#include <memory>
#include <vector>

class C {
public:
  void foo()       { std::cout << "A"; }
  void foo() const { std::cout << "B"; }
};

struct S {
  std::vector<C> v;
  std::unique_ptr<C> u;
  C *const p;

  S() 
    : v(1) 
    , u(new C())
    , p(u.get())
  {}
};

void constness_01()
{
  std::cout << "Constness." << std::endl;
  S s;
  const S &r = s;
 
  // all call non-const foo
  s.v[0].foo();
  s.u->foo();
  s.p->foo();

  // only this calls const foo
  r.v[0].foo();

  // these call non-const
  // The cv-qualifiers apply to the pointer and not the object
  // Constness is shallow regarding pointers and references
  // Not shallow with regard to standard containers
  // [] returns const C& (vector is const-correct)
  r.u->foo();
  r.p->foo();
}

