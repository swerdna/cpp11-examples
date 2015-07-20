cmake_minimum_required(VERSION 2.8)

# chrono

project ( c++11-chrono )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( CHRONO_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/chrono.cpp
    )

add_executable ( c++11-chrono ${CHRONO_SOURCES} )

