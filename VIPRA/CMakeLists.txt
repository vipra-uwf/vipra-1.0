cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME VIPRA_SIM)

option(DEBUG_MODE "Compile In Debug Mode" OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)

set(MODULES_DIR ./../Modules)
set(BASE_DIR ./Base)
set(DEPS_DIR ./deps)
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

add_subdirectory(${BEHAVIORS_DIR}/dsl dsl)
add_subdirectory(${DEPS_DIR})

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  VIPRA_Dependencies
  VIPRA_Behaviors
)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../)

set(COMP_OPTIONS -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wundef -Werror -Wno-unused)

if (DEBUG_MODE)
  set(COMP_OPTIONS ${COMP_OPTIONS} -g -DDEBUG_OUTPUT -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment)
  target_link_options(${PROJECT_NAME} PUBLIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment)
endif ()

target_compile_options(${PROJECT_NAME} PUBLIC ${COMP_OPTIONS})

add_subdirectory(${BASE_DIR})
add_subdirectory(${MODULES_DIR} modules)

include_directories(
  SYSTEM
  ${BEHAVIORS_DIR}
  ${DEPS_DIR}
  ${DEPS_DIR}/antlr4-runtime
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ${MODULES_DIR}
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)