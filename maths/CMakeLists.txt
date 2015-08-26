cmake_minimum_required(VERSION 2.8)

# math

project ( c++-math )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )
include_directories( ${CMAKE_CURRENT_LIST_DIR} )

set ( MATH_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/math_main.cpp
    )

add_executable ( c++-math ${MATH_SOURCES} )


