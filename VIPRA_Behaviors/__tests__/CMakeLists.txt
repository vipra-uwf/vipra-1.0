cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME Behavior_Tests)
set(CMAKE_BUILD_TYPE Debug)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(BASE_DIR ./../../VIPRA/Base Base)
set(DEPS_DIR ./../../VIPRA/deps deps)
set(BEHAVIOR_DIR ./../ dsl)
set(EXTENDABLE_DIR ./../../VIPRA/Extendable extendable)

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

include_directories(
  SYSTEM
  ${DEPS_DIR}
  ${DEPS_DIR}/antlr4-runtime
)

add_subdirectory(${BEHAVIOR_DIR})

target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  GTest::gmock_main
  spdlog::spdlog
  VIPRA_Behaviors
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} )

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ./
  ${BASE_DIR}
  ${BEHAVIOR_DIR}/include
  ${EXTENDABLE_DIR}
)

add_subdirectory(parsing_tests)
add_subdirectory(selector_tests)