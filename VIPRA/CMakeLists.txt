cmake_minimum_required(VERSION 3.15)

option(GEN_MAIN "Create Generate Main" ON)
option(DEBUG_MODE "Compile In Debug Mode" OFF)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)

set(MODULES_DIR ./../Modules)
set(BASE_DIR ./Base)
set(DEPS_DIR ./deps)
set(EXTENDABLE_DIR ./Extendable)

if (GEN_MAIN)

  set(PROJECT_NAME generate_main)

  project(
    ${PROJECT_NAME} 
    VERSION 0.0.1
    DESCRIPTION "VIPRA pedestrian dynamics simulation code generator"
    LANGUAGES CXX
  )
  
  add_executable(
    ${PROJECT_NAME}
    ${BASE_DIR}/code_generation/code_generator.cpp 
    ${BASE_DIR}/configuration/configuration_reader.cpp
  )
  add_subdirectory(${DEPS_DIR}/jsoncpp)
  target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    jsoncpp
  )

else()

  set(PROJECT_NAME VIPRA_SIM)

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
  add_subdirectory(${DEPS_DIR})
  target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    ANTLR4
    jsoncpp
    lumberjack
    generated_antlr
  )
    
  add_subdirectory(${BASE_DIR})
  add_subdirectory(${MODULES_DIR} build)
  
endif(GEN_MAIN)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../ )


if (DEBUG_MODE)
  target_compile_options(${PROJECT_NAME} PUBLIC -g -O0)
  target_compile_options(${PROJECT_NAME} PUBLIC -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment)
  target_link_options(${PROJECT_NAME} PUBLIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment)
endif ()

target_compile_options(${PROJECT_NAME} PUBLIC -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Werror -Wno-unused)

include_directories(
  SYSTEM
  ${DEPS_DIR}
  ${DEPS_DIR}/antlr4-runtime
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${MODULES_DIR}
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)