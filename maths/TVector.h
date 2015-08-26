#ifndef TVECTOR_H_INCLUDED
#define TVECTOR_H_INCLUDED

#include <array>
#include <initializer_list>

namespace NMath
{

// length of vector
template< int N, typename T = double >
class TVector
{
    public:
        TVector()
        {
            std::fill( m_data.begin(), m_data.end(), T(0) );
        }

        template <typename T1, typename... Types>
        TVector( T1 t, Types... ts )
            : m_data{ { t, ts... } }
        {
        }

        T& operator[](size_t i)
        {
            return m_data[i];
        }
        
        const T& operator[](size_t i) const
        {
            return m_data[i];
        }
    private:
        std::array< T, N > m_data;
};

}

#endif  // TVECTOR_H_INCLUDED
