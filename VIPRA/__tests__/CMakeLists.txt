
cmake_minimum_required(VERSION 3.15)
SET(PROJECT_NAME vipra_tests)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)

set(MODULES_DIR ./../../Modules Modules)
set(BASE_DIR ./../Base Base)
set(BEHAVIOR_DIR ./../../VIPRA_Behaviors behaviors)
set(EXTENDABLE_DIR ./../Extendable Extendable)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

project(
  ${PROJECT_NAME} 
  VERSION 0.0.1
  DESCRIPTION "VIPRA pedestrian dynamics simulation"
  LANGUAGES CXX
)

add_executable(
  ${PROJECT_NAME}
  Testing.cpp
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})


add_subdirectory(${MODULES_DIR})
add_subdirectory(${BASE_DIR})
add_subdirectory(${BEHAVIOR_DIR})

target_link_libraries(
  ${PROJECT_NAME}
  GTest::gtest_main
  GTest::gmock_main
  nlohmann_json::nlohmann_json
  spdlog
  VIPRA_Behaviors
)

add_subdirectory(modules)
add_subdirectory(base)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ./
  ${MODULES_DIR}
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)


include_directories(
  SYSTEM
  ${DEPS_DIR}
  ${SPDLOG_DIR}
  ${JSON_DIR}
  ${BEHAVIOR_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR} )