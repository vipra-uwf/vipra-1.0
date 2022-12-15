cmake_minimum_required(VERSION 3.16)
project(Jsoncpp)

add_library(jsoncpp json/json-forwards.h json/json.h jsoncpp.cpp)
target_include_directories(jsoncpp PUBLIC json/)