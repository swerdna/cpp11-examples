#ifndef CMATRIX_INCLUDED
#define CMATRIX_INCLUDED

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <cassert>

namespace NMath
{

template< typename T >
class CMatrix
{
    public:
        explicit CMatrix( int m, int n )
            : m_n(n), m_m(m)
        {
            m_data.resize(m*n);
        }

        T & at( int m, int n )
        {
            assert( n < m_n && m < m_m );
            return m_data[ n * m_m + m ];
        }

        const T & at( int m, int n ) const
        {
            assert( n < m_n && m < m_m );

            return m_data[ n * m_m + m ];
        }

        T inner_product( const CMatrix &l_mat ) const
        {
            if ( l_mat.m_n != m_n || l_mat.m_m != m_m )
            {
                throw std::exception(  );
            }

            T l_sum( 0 );
            for ( int i = 0; i < m_data.size(); ++i )
            {
                l_sum += m_data[i] * l_mat.m_data[i];
            }
            return l_sum;
        }

        CMatrix cross_product( const CMatrix &l_mat ) const
        {
            if (m_n != l_mat.m_m)
            {
                throw std::exception();
            }
            CMatrix l_res(m_m, l_mat.m_n);

            for (int i = 0; i < m_m; ++i)
            {
                for (int j = 0; j < l_mat.m_n; ++j)
                {
                    for (int k = 0; k < m_n; ++k)
                    {
                        l_res.at(i, j) += at( i, k ) * l_mat.at( k, j );
                    }
                }
            }
            return l_res;
        }

        CMatrix transpose() const
        {
            CMatrix l_res( m_n, m_m );
            for (int i=0; i < m_m; ++i)
            {
                for ( int j=0; j < m_n; ++j)
                {
                    l_res.at(j,i) = at(i,j);
                }
            }
            return l_res;
        }

        CMatrix submatrix( const std::vector< int > &m_rowsToRemove, const std::vector< int > &m_colsToRemove ) const
        {
            CMatrix l_res( m_m - m_rowsToRemove.size(), m_n - m_colsToRemove.size() );

            int l_resM = 0, l_resN = 0;
            for (int i = 0; i < m_m; ++i)
            {
                if (m_rowsToRemove.end() != std::find( m_rowsToRemove.cbegin(), m_rowsToRemove.cend(), i ))
                {
                    continue;
                }
                for (int j=0; j < m_n; ++j)
                {
                    if (m_colsToRemove.end() != std::find( m_colsToRemove.cbegin(), m_colsToRemove.cend(), i ))
                    {
                        continue;
                    }
                    l_res.at(l_resM, l_resN) = at(i,j);
                    ++l_resN;
                }
                ++ l_resM;
            }
            return l_res;
        }

        void draw( std::ostream & ) const;

    private:
        int m_n, m_m;

        std::vector< T > m_data;
};

}

#endif // CMATRIX_INCLUDED
