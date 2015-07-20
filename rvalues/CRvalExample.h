#pragma once

#include <iosfwd>

namespace cpp11_examples
{

class CRvalExample
{
  public:
    /**
     * Runs the r-value examples
     *
     * @param ar_str the output stream to write to
     */
    static int run( std::ostream &ar_str );
};

}
