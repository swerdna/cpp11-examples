cmake_minimum_required(VERSION 2.8)

# decltype, auto

project ( c++11-decltype )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( DECLTYPE_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/decltype.cpp
    )

add_executable ( c++11-decltype ${DECLTYPE_SOURCES} )

