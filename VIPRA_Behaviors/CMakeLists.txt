cmake_minimum_required(VERSION 3.14)

SET(VIPRA_DIR ./../VIPRA)
SET(DEPS_DIR ./../VIPRA/deps)

SET(GRAMMAR_DIR ./grammar)
SET(INCLUDE_DIR ./include)
SET(SRC_DIR ./src)


SET(LIB_NAME VIPRA_Behaviors)
project(${LIB_NAME})

SET(SRCS
  ${SRC_DIR}/actions/action.cpp
  ${SRC_DIR}/actions/atoms/atom_stop.cpp
  ${SRC_DIR}/actions/atoms/atom_be.cpp
  ${SRC_DIR}/actions/atoms/atom_change_speed.cpp
  ${SRC_DIR}/behavior/behavior_builder.cpp
  ${SRC_DIR}/behavior/behavior_error_listener.cpp
  ${SRC_DIR}/behavior/human_behavior.cpp
  ${SRC_DIR}/conditions/condition.cpp
  ${SRC_DIR}/conditions/subconditions/subcondition_elapsed_time.cpp
  ${SRC_DIR}/conditions/subconditions/subcondition_event.cpp
  ${SRC_DIR}/conditions/subconditions/subcondition_start.cpp
  ${SRC_DIR}/conditions/subconditions/subcondition_event_occurring.cpp
  ${SRC_DIR}/conditions/subconditions/subcondition_event_one_time.cpp
  ${SRC_DIR}/selectors/pedestrian_groups.cpp
  ${SRC_DIR}/selectors/selector.cpp
  ${SRC_DIR}/selectors/selector_everyone.cpp
  ${SRC_DIR}/selectors/selector_exactly_N.cpp
  ${SRC_DIR}/selectors/selector_percent.cpp
  ${SRC_DIR}/selectors/subselector.cpp
  ${SRC_DIR}/events/event.cpp
  ${SRC_DIR}/definitions/directions.cpp
  ${SRC_DIR}/definitions/object.cpp
  ${GRAMMAR_DIR}/generated/BehaviorVisitor.cpp
  ${GRAMMAR_DIR}/generated/BehaviorLexer.cpp
  ${GRAMMAR_DIR}/generated/BehaviorParser.cpp
  ${GRAMMAR_DIR}/generated/BehaviorBaseVisitor.cpp
)

SET(HEADERS
  ${INCLUDE_DIR}/behavior/human_behavior.hpp
  ${INCLUDE_DIR}/behavior/behavior_builder.hpp
)

add_library(
  ${LIB_NAME}
  STATIC
  ${SRCS}
)

target_include_directories(
  ${LIB_NAME}
  PUBLIC
  ${INCLUDE_DIR}
  ${GRAMMAR_DIR}
)

add_subdirectory(${DEPS_DIR}/spdlog sl)
add_subdirectory(${DEPS_DIR}/antlr4-runtime antlr)

include_directories(
  SYSTEM
  .
  ${VIPRA_DIR}/Base
  ${VIPRA_DIR}/Extendable
  ${DEPS_DIR}
)

target_link_libraries(
  ${LIB_NAME}
  ANTLR4
  spdlog::spdlog
)