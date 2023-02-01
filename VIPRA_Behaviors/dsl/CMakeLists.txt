cmake_minimum_required(VERSION 3.14)
set(VIPRA_DIR ./../../VIPRA)
set(DEPS_DIR ./../../VIPRA/deps)

file(
  GLOB
  behavior_srcs
  *.cpp
  */*.cpp
)

Set(LIB_NAME VIPRA_Behaviors)
project(${LIB_NAME})
add_library(${LIB_NAME} ${behavior_srcs})

target_link_libraries(
  ${LIB_NAME}
  PUBLIC
  ANTLR4
  spdlog
)

include_directories(
  SYSTEM
  .
  ${VIPRA_DIR}/Base
  ${VIPRA_DIR}/Extendable
  ${DEPS_DIR}
  )
  
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)