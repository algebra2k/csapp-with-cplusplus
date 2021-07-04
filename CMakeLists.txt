cmake_minimum_required (VERSION 3.8)

project ("csapp")

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(src/libs)

include_directories(${CMAKE_SOURCE_DIR}/src/libs)
link_directories(BEFORE ${CMAKE_SOURCE_DIR}/src/libs)

add_subdirectory(src/0x02)