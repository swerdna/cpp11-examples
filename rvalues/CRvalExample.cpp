#include "CRvalExample.h"
#include "CRval.h"
#include <iostream>
#include <utility>

namespace cpp11_examples
{

int CRvalMember::s_member_copies = 0;
int CRval::s_destructs = 0;
int CRval::s_copy_constructs = 0;

// the implicit move constructor
struct A
{
    A()
    {
        ++s_constructs;
    }

    // This is needed if not defined explicitly, check rules on when this is provided
    // A( A&& a_mv ) = default;

    A( A&& a_mv )
        : i(a_mv.i)
        , m(std::forward<CRvalMember>(a_mv.m))
    {
        ++s_moves;
    }

    A( const A& ar_init )
    {
        ++s_copies;
        i = ar_init.i;
    }
    A& operator=(const A& ar_rhs)
    {
        ++s_assignments;
        i = ar_rhs.i;
        return *this;
    }
    int i = 7;
    CRvalMember m;
    static int s_copies;
    static int s_moves;
    static int s_assignments;
    static int s_constructs;
};

int A::s_copies = 0;
int A::s_moves = 0;
int A::s_assignments = 0;
int A::s_constructs = 0;

struct B
{
    A makeA()
    {
        A a;
        a.i = 9;
        // std::forward or move can be used to force move here.
        // otherwise, return value optimization may be applied.
        return std::move(a);
    }
};

int CRvalExample::run( std::ostream& ar_str )
{
    using std::endl;
    ar_str << "---------------" << endl
           << "RValue example " << endl
           << "---------------" << endl;

    {
        ar_str << "Creating a class via move (rvalue) initialization" << endl;
        CRval l_valProto;

        ar_str << "Location of prototype's string: " << (void*) l_valProto.m_str.data() << endl;
        CRval l_val2( std::move(l_valProto) );

        ar_str << "Location of new object's string: " << (void*) l_val2.m_str.data() << endl;

        CRval l_val3( std::forward<CRval>(l_val2) );
        ar_str << "using std::forward instead: " << (void*) l_val3.m_str.data() << endl;
    }
    ar_str << "Count of destructs: " << CRval::s_destructs << endl;
    ar_str << "Count of copies: " << CRval::s_copy_constructs << endl;
    ar_str << "Count of member copies: " << CRvalMember::s_member_copies << endl;

    // Check that the move operator is used for the return from b.makeA
    {
        B b;
        // I think return value optimization happens here
        A a = b.makeA();
        std::cout << "val of a.i = " << a.i << std::endl;
    }
    ar_str << "Count of A copies: " << A::s_copies << endl;
    ar_str << "Count of A asssignments: " << A::s_assignments << endl;
    ar_str << "Count of A constructs: " << A::s_constructs << endl;
    ar_str << "Count of A moves: " << A::s_moves << endl;
    ar_str << "Count of CRvalMember copies: " << CRvalMember::s_member_copies << endl;

    A::s_copies = A::s_assignments = A::s_constructs = A::s_moves = 0;
    // Check that the move operator is used for the return from b.makeA
    {
        A a;
        ar_str << "Location of prototype's string: " << (void*) a.m.m_str.data() << endl;
        // The move constructor is called here
        A a2(std::forward<A>(a));
        ar_str << "Location of moved string: " << (void*) a2.m.m_str.data() << endl;
        // The copy constructor is called here
        A a3(a2);

        std::cout << "val of a.i = " << a.i << std::endl;
    }

    ar_str << "Count of A copies: " << A::s_copies << endl;
    ar_str << "Count of A asssignments: " << A::s_assignments << endl;
    ar_str << "Count of A constructs: " << A::s_constructs << endl;
    ar_str << "Count of A moves: " << A::s_moves << endl;
    ar_str << "Count of CRvalMember copies: " << CRvalMember::s_member_copies << endl;
    A::s_copies = A::s_assignments = A::s_constructs = A::s_moves = 0;
    return 0;
}

}
