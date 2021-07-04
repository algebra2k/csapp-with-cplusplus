cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)

set (SOURCE_FILES show_bytes.cc csapp.h)

add_library(csapp STATIC ${SOURCE_FILES})