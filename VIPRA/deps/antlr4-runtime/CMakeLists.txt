

file(GLOB
antlr4_srcs
*.cpp
*/*.cpp
*/*/*.cpp
*/*/*/*.cpp
)

cmake_minimum_required(VERSION 3.1)
project(ANTLR4)
add_library(ANTLR4 ${antlr4_srcs})
target_include_directories(ANTLR4 PUBLIC .)
set_target_properties(ANTLR4 PROPERTIES LINKER_LANGUAGE CXX)
