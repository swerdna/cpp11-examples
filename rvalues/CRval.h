#pragma once

#include <string>

namespace cpp11_examples
{

struct CRvalMember
{
    CRvalMember( )
    {
    }
    CRvalMember( CRvalMember &&ar_mv )
      : m_int(ar_mv.m_int)
      , m_str(ar_mv.m_str)
    {
    }

    int m_int = 1;
    std::string m_str = "One";
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

    // counting destructor
    ~CRval()
    {
        ++s_destructs;
    }

  public:
    static int s_destructs;

  private:
    CRval( const CRval & );

  public:
    CRvalMember m_member;
    int         m_int = 42;
    std::string m_str = "The meaning";
};

}

