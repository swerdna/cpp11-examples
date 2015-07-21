cmake_minimum_required(VERSION 2.8)

# scopes

project ( c++11-scopes )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( SCOPES_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/scopes.cpp
    )

add_executable ( c++11-scopes ${SCOPES_SOURCES} )


