cmake_minimum_required(VERSION 3.14)

Set(PROJECT_NAME VIPRA_Dependencies)
project(${PROJECT_NAME})



add_subdirectory(antlr4-runtime)
add_subdirectory(jsoncpp)
add_subdirectory(spdlog)

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(
  ${PROJECT_NAME}
  INTERFACE
  ANTLR4
  jsoncpp
  spdlog::spdlog
)