#include <iostream>
#include "misc_examples.h"

void strange_array_notation()
{
    std::cout << "Strange array notation..   e.g.  5[\"abcdef\"] is equivalent to \"abcdef\"[5]" << std::endl;
    std::cout << "1[\"ABC\"]   =>   " << 1["ABC"]
              << std::endl;
}
