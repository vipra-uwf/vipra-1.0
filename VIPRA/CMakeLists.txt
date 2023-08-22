cmake_minimum_required(VERSION 3.18)
set(PROJECT_NAME VIPRA_SIM)

option(DEBUG_MODE "Compile In Debug Mode" OFF)
option(PROF_MODE "Build With Profiling Output" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(MODULES_DIR ./../Modules)
set(BASE_DIR ./Base)
set(EXTENDABLE_DIR ./Extendable)
set(BEHAVIORS_DIR ./../VIPRA_Behaviors)

project(
  ${PROJECT_NAME}
  VERSION 0.0.1
  DESCRIPTION "VIPRA pedestrian dynamics simulation"
  LANGUAGES CXX
)

add_executable(
  ${PROJECT_NAME}
  main.cpp
)

target_compile_options(
  ${PROJECT_NAME} 
  PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror -Wpedantic >
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../)

if (DEBUG_MODE)
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
  set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")
else()
  set(CMAKE_BUILD_TYPE Release)
  if (PROF_MODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
  else()
    include(CheckIPOSupported)
    check_ipo_supported(RESULT supported OUTPUT error)
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
  endif()
endif ()

include(FetchContent)
message(STATUS "Getting spdlog")
FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/v1.11.0.tar.gz)
FetchContent_MakeAvailable(spdlog)
message(STATUS "Done Getting spdlog")

message(STATUS "Getting nlohmann_json")
FetchContent_Declare(nlohmann_json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(nlohmann_json)
message(STATUS "Done Getting nlohmann_json")

add_subdirectory(${BASE_DIR})
add_subdirectory(${MODULES_DIR} modules)
add_subdirectory(${BEHAVIORS_DIR} behaviors)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${MODULES_DIR}
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  VIPRA_Behaviors
  spdlog::spdlog
  nlohmann_json::nlohmann_json
)