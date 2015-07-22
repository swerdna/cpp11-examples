cmake_minimum_required(VERSION 2.8)

# misc

project ( c++11-misc )

include ( ${CMAKE_CURRENT_LIST_DIR}/../build/CMakeClang.txt )

set ( MISC_SOURCES
      ${CMAKE_CURRENT_LIST_DIR}/misc.cpp
      ${CMAKE_CURRENT_LIST_DIR}/misc_crtp_01.cpp
      ${CMAKE_CURRENT_LIST_DIR}/strange_array_notation.cpp
      ${CMAKE_CURRENT_LIST_DIR}/constness.cpp
      ${CMAKE_CURRENT_LIST_DIR}/copy_direct_initialization.cpp
      # examples that don't compile, illustrating language rules
      # ${CMAKE_CURRENT_LIST_DIR}/wont_compile_0001_call_override_from_base_in_constructor.cpp
    )

add_executable ( c++11-misc ${MISC_SOURCES} )

