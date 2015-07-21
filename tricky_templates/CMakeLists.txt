cmake_minimum_required(VERSION 2.8)

# tricky templates

project ( c++11-templates )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( TT_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/tricky_templates.cpp
    )

add_executable ( c++11-tricky-templates ${TT_SOURCES} )

