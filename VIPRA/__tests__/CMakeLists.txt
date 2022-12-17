cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME Vipra_tests)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR}/../Base Base)
set(MODULES_DIR ${CMAKE_CURRENT_LIST_DIR}/../../Modules Modules)
set(DEPS_DIR ${CMAKE_CURRENT_LIST_DIR}/../deps deps)
set(EXTENDABLE_DIR ${CMAKE_CURRENT_LIST_DIR}/../Extendable Extendable)


include_directories(
  ${BASE_DIR}
  ${MODULES_DIR}
  ${DEPS_DIR}
  ${EXTENDABLE_DIR}
  .
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ${PROJECT_NAME}
  Testing.cpp
)

add_subdirectory(${DEPS_DIR})
target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  lumberjack
  jsoncpp
  ANTLR4 
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} )

add_subdirectory(modules)
add_subdirectory(base)
add_subdirectory(human_behavior)

add_subdirectory(${MODULES_DIR})
add_subdirectory(${BASE_DIR})