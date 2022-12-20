cmake_minimum_required(VERSION 3.1)
project(generated_antlr)

set(DEPS_DIR ../../../deps deps)

file(
  GLOB
  generated_srcs
  *.cpp
  */*.cpp
)

add_library(generated_antlr ${generated_srcs})
target_link_libraries(
  generated_antlr
  PUBLIC
  ANTLR4
)

set_target_properties(generated_antlr PROPERTIES LINKER_LANGUAGE CXX)