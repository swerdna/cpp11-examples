#include "algo.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

// A heap is a tree, with array storage

// Min heap
//
// * parent node value <= children



// Max heap
// * parent node value > children  ( or >= ? )

template< typename T >
void print_heap( const T& a_heap )
{
    std::cout << '+';
    for ( size_t i = 0; i < a_heap.size(); ++i )
    {
        std::cout << "----+";
    }
    std::cout << '\n';
    for ( auto &&i : a_heap )
    {
        std::cout << "| " << std::setw(2) << std::setfill(' ') << i << ' ';
    }
    std::cout << "|\n";

    std::cout << '+';
    for ( size_t i = 0; i < a_heap.size(); ++i )
    {
        std::cout << "----+";
    }
    std::cout << std::endl;
}

template< typename T, typename V >
void min_heap_insert( T& a_heap, V&& val )
{
    a_heap.push_back( val );
    size_t i = a_heap.size() - 1;
    while ( i > 0 && a_heap[i] < a_heap[ (i-1)/2 ] )
    {
        std::swap( a_heap[i], a_heap[ (i-1)/2 ] );
        i = (i-1)/2;
    }
}

template< typename T, typename V >
void min_heap_remove( T& a_heap, const V& val )
{
  // slow version, visit every node.
  auto l_iter = a_heap.begin();
  size_t l_index = 0;
  while (a_heap.end() != l_iter)
  {
    if (val == *l_iter)
    {
        // swap with the last element in the heap, then resize
        (*l_iter) = a_heap[ a_heap.size() - 1 ];
        a_heap.resize( a_heap.size() - 1 );
        auto left = []( size_t ind ) { return 2*ind + 1; };
        auto right = []( size_t ind ) { return 2*ind + 2; };

        // shuffle this and children to be sorted
        while ( (left(l_index) < a_heap.size() && a_heap[ l_index] > a_heap[ left(l_index) ])
              || (right(l_index) < a_heap.size() && a_heap[ l_index ] > a_heap[ right( l_index ) ] ))
        {
            if ( a_heap[ left(l_index) ] < a_heap[ right( l_index ) ] )
            {
                std::swap( a_heap[left(l_index)], a_heap[l_index] );
                l_index = left(l_index); 
            }
            else
            {
                std::swap( a_heap[right(l_index)], a_heap[l_index] );
                l_index = right(l_index); 
            }
        }
        break;
    }
    ++ l_index;
    ++ l_iter;
  }
}

void min_heap_test()
{
    std::cout << "TESTING MIN HEAP" << std::endl;
    std::vector<int> l_heap;

    const std::array< int, 5 > l_values = {{ 3, 9, 12, 7, 1 }};

    for (auto &&i : l_values)
    {
        std::cout << "Insert " << i << '\n';
        min_heap_insert( l_heap, i );
        print_heap( l_heap );
    }

    for (auto&& i : l_values )
    {
        std::cout << "Remove " << i << '\n';
        min_heap_remove( l_heap, i );
        print_heap( l_heap );
    }

}

void heap_tests()
{
    min_heap_test();
}
