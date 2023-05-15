cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME generate_main)

option(MODULES_PATH "Path To Modules File" "")
option(DEBUG_MODE "Compile In Debug Mode" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(BASE_DIR ./../)

project(
  ${PROJECT_NAME}
  VERSION 0.0.1
  DESCRIPTION "Main Generator For VIPRA"
  LANGUAGES CXX
)

add_executable(
  ${PROJECT_NAME}
  ./code_generator.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../)

include(FetchContent)
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/v1.11.0.tar.gz)
FetchContent_MakeAvailable(spdlog)

set(JSONCPP_WITH_TESTS OFF)
FetchContent_Declare(jsoncpp URL https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.9.3.tar.gz)
FetchContent_MakeAvailable(jsoncpp)

add_subdirectory(${BASE_DIR}/configuration configuration)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${BASE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  spdlog::spdlog
  jsoncpp_lib
)