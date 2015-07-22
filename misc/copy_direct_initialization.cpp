#include "misc_examples.h"
#include <iostream>

struct C
{
    explicit C(int)
    {
        std::cout << "i";
    }
    C(double)
    {
        std::cout << "d";
    }
};

void copy_direct_initialization()
{
    std::cout << "Copy / direct initialization" << std::endl;
    // explicit constructor used
    C a(7);
    // copy initialization - explicit constructor will be ignored
    C b = 7;
}
