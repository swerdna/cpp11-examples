#include "misc_examples.h"
#include <iostream>

template< typename T >
class Base
{
    public:
        Base()
        {
            // This isn't safe, but it compiles and runs.
            // the T part of this isn't constructed yet.
            static_cast<T*>(this)->construct();
        }

        void print_a() const
        {
            std::cout << "a=" << static_cast<const T*>(this)->a << std::endl;
        }
};

class A : public Base<A>
{
    public:
        void construct()
        {
            std::cout << "Constructed, a=" << a << std::endl;
        }

        int a = 5;
};

void crtp_01()
{
    std::cout << "CRTP example" << std::endl;
    A l_base;
    l_base.print_a();
}

