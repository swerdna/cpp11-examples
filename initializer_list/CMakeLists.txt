cmake_minimum_required(VERSION 2.8)

# initializer list

project ( c++11-initializer-list )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( INITLIST_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/initializer-list.cpp
    )

add_executable ( c++11-initializer-list ${INITLIST_SOURCES} )

