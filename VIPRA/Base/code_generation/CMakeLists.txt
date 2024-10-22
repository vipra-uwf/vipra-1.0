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

if (DEBUG_MODE)
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
  set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../)

include(FetchContent)
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/v1.11.0.tar.gz)
FetchContent_MakeAvailable(spdlog)

message(STATUS "Getting nlohmann_json")
FetchContent_Declare(nlohmann_json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(nlohmann_json)
message(STATUS "Done Getting nlohmann_json")

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
  nlohmann_json::nlohmann_json
)