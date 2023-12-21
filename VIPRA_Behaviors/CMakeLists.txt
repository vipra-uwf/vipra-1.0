cmake_minimum_required(VERSION 3.14)
set(LIB_NAME VIPRA_Behaviors)
project(${LIB_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(VIPRA_DIR ./../VIPRA)
set(GRAMMAR_DIR ./grammar)
set(INCLUDE_DIR ./include)
set(SRC_DIR ./src)
set(PERF_TEST_DIR ./performance)

add_library(
  ${LIB_NAME}
  ${SRCS}
)

add_subdirectory(${SRC_DIR})
add_subdirectory(${GRAMMAR_DIR})
add_subdirectory(${PERF_TEST_DIR})

target_include_directories(
  ${LIB_NAME}
  PUBLIC
  ${INCLUDE_DIR}
  ${GRAMMAR_DIR}
  ${PERF_TEST_DIR}
)

include(FetchContent)
message(STATUS "Getting spdlog")
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/v1.11.0.tar.gz)
FetchContent_MakeAvailable(spdlog)
message(STATUS "Done Getting spdlog")

message(STATUS "Setting Up ANTLR")
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/antlr_setup )
include( ExternalAntlr4Cpp )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Done Setting Up ANTLR")

message(STATUS "Getting nlohmann_json")
FetchContent_Declare(nlohmann_json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(nlohmann_json)
message(STATUS "Done Getting nlohmann_json")

target_link_libraries(
  ${LIB_NAME}
  PUBLIC
  antlr4_shared
  spdlog::spdlog
  nlohmann_json::nlohmann_json
)

include_directories(
  SYSTEM
  .
  ${VIPRA_DIR}/Base
  ${VIPRA_DIR}/Extendable
  ${ANTLR4CPP_INCLUDE_DIRS}
)