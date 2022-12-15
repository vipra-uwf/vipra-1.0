cmake_minimum_required(VERSION 3.1)
project(LumberJack)

add_library(lumberjack lumberjack.hpp loggers/consoleLogger.hpp loggers/fileLogger.hpp)
target_include_directories(lumberjack PUBLIC include/)
set_target_properties(lumberjack PROPERTIES LINKER_LANGUAGE CXX)