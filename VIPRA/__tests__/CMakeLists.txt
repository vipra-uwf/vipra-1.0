cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME Vipra_tests)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(MODULES_DIR ./../../Modules Modules)
set(BASE_DIR ./../Base Base)
set(DEPS_DIR ./../deps deps)
set(EXTENDABLE_DIR ./../Extendable Extendable)

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

add_subdirectory(${DEPS_DIR})
target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  GTest::gmock_main
  ANTLR4
  jsoncpp
  lumberjack
  generated_antlr
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} )

add_subdirectory(${MODULES_DIR})
add_subdirectory(${BASE_DIR})

add_subdirectory(modules)
add_subdirectory(base)
add_subdirectory(human_behavior)

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ./
  ${MODULES_DIR}
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)