#pragma once

#include <string>

namespace cpp11_examples
{

struct CRvalMember
{
    CRvalMember( )
    {
    }

    CRvalMember( CRvalMember &&ar_mv ) = default;

    CRvalMember( const CRvalMember &ar_copy )
    {
        ++s_member_copies;
        m_int = ar_copy.m_int;
        m_str = ar_copy.m_str;
    }

    int m_int = 1;
    std::string m_str = "One";

    static int s_member_copies;
};

class CRval
{
  public:
    // default initializaiton
    CRval( )
    {
    }

    // initialization via move
    CRval( CRval &&ar_mv ) = default;

    // copy constructing
    CRval( const CRval &ar_mv )
        : m_member( ar_mv.m_member )
    {
        ++s_copy_constructs;
    }

    // counting destructor
    ~CRval()
    {
        ++s_destructs;
    }

  public:
    static int s_destructs;
    static int s_copy_constructs;

  public:
    CRvalMember m_member;
    int         m_int = 42;
    std::string m_str = "The meaning";
};

}

