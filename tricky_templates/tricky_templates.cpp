#include <iostream>

using namespace std;

struct A {};
struct B {};

template<typename T = A>
struct X;

template<>
struct X<A> {
   static void f() { cout << 1 << endl; }
};

template<>
struct X<B> {
   static void f() { cout << 2 << endl; }
};

// C<B> is (X<B>) is called.
template< template<typename T = B> class C>
void g() {
   C<>::f();
}

template< template<typename T = A> class C>
void h() {
   C<>::f();
}

template< class C >
void i() {
   C::f();
}

int main() {
   g<X>();
   h<X>();
   i<X<A>>();
   i<X<B>>();
   i<X<>>();
}

