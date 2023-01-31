cmake_minimum_required(VERSION 3.14)
set(VIPRA_DIR ./../../VIPRA)
set(DEPS_DIR ./../../VIPRA/deps)

file(
  GLOB
  behavior_srcs
  *.cpp
  */*.cpp
)

Set(PROJECT_NAME VIPRA_Behaviors)
project(${PROJECT_NAME})
add_library(${PROJECT_NAME} ${behavior_srcs})

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  ANTLR4
  spdlog
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC 
  .
  ${VIPRA_DIR}/Base
  ${VIPRA_DIR}/Extendable
  ${DEPS_DIR}
  )
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)