#include "CMatrix.h"
#include "TVector.h"


int main( int argc, char ** argv )
{
    NMath::CMatrix< int > l_matrix( 2, 2 );

    auto l_dot = l_matrix.inner_product(l_matrix);
    auto i = l_matrix.at( 1, 1 );

    auto l_res = l_matrix.cross_product( l_matrix );
    auto l_trans = l_res.transpose();

    NMath::TVector<4, int> l_intVec { 1, 2, 3, 4 };
    NMath::TVector<4, int> l_intVec2(l_intVec);
    NMath::TVector<4, int> l_intVec3;
    l_intVec3 = l_intVec;

    return 0;
}
