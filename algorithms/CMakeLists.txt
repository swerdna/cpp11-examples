cmake_minimum_required(VERSION 2.8)

# algorithms

project ( c++-algorithms )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( ALGO_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/algo.cpp
      ${CMAKE_CURRENT_LIST_DIR}/heaps.cpp
    )

add_executable ( c++-algorithms ${ALGO_SOURCES} )

