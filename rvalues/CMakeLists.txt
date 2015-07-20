cmake_minimum_required(VERSION 2.8)

# R-values

project ( c++11-rvalues )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( RVAL_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/rval.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CRvalExample.cpp
    )

add_executable ( c++11-rvalues ${RVAL_SOURCES} )
