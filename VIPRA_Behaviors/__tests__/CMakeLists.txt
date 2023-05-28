cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME Behavior_Tests)
set(CMAKE_BUILD_TYPE Debug)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(BEHAVIORS_DIR ..)
set(SRCS_DIR src)
set(VIPRA_DIR ../../VIPRA)


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

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} )

add_subdirectory(${BEHAVIORS_DIR} behaviors)
add_subdirectory(${SRCS_DIR})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${SRCS_DIR}
  ${VIPRA_DIR}/Base
  ${VIPRA_DIR}/Extendable
  ${VIPRA_DIR}/__tests__/
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  GTest::gtest_main
  GTest::gmock_main
  VIPRA_Behaviors
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})