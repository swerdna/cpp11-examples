#include "CRvalExample.h"
#include "CRval.h"
#include <iostream>

namespace cpp11_examples
{
int CRval::s_destructs = 0;

int CRvalExample::run( std::ostream& ar_str )
{
    using std::endl;
    ar_str << "---------------" << endl
           << "RValue example " << endl
           << "---------------" << endl;

    ar_str << "Creating a class via move (rvalue) initialization" << endl;
    CRval l_valProto;
    ar_str << "Location of prototype's string: " << (void*) l_valProto.m_str.data() << endl;
    CRval l_val2( std::move(l_valProto) );
    ar_str << "Location of new object's string: " << (void*) l_val2.m_str.data() << endl;
    return 0;
}

}
