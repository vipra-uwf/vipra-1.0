cmake_minimum_required(VERSION 3.15)

option(GEN_MAIN "Create Generate Main" ON)


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
    ${DEPS_DIR}/jsoncpp/jsoncpp.cpp 
    ${BASE_DIR}/configuration/configuration_reader.cpp
  )

  set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../ )
  
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
    PRIVATE
    ANTLR4
    jsoncpp
    lumberjack
  )
    
  add_subdirectory(${BASE_DIR})
  add_subdirectory(${MODULES_DIR} build)

  set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../ )


endif(GEN_MAIN)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${DEPS_DIR}
  ${DEPS_DIR}/antlr4-runtime
  ${BASE_DIR}
  ${EXTENDABLE_DIR}
)