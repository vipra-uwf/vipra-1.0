CXX = g++
NAME = "generated_main"
CXXFLAGS = -std=c++11 -g -Wall -O3 -fopenmp -fPIE

BUILD_DIR = build
SRCS = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
SRCS := $(filter-out code_generation/code_generator.cpp, $(SRCS)) #this gets compiled separately
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: compile
compile: setup generate_main make_directories main

generate_main:
	$(CXX) $(CXXFLAGS) code_generation/code_generator.cpp jsoncpp/jsoncpp.cpp configuration/configuration_reader.cpp -o $@
	./$@
	rm ./$@
	$(eval SRCS := $(NAME).cpp)
	echo $(OBJECTS)
	
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^
	
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

setup:
	@test -e rapidxml || git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git rapidxml
	@rm -rf ./rapidxml/.git
	@rm -rf ./rapidxml/test

make_directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/configuration
	@mkdir -p $(BUILD_DIR)/code_generation
	@mkdir -p $(BUILD_DIR)/definitions
	@mkdir -p $(BUILD_DIR)/entity_sets
	@mkdir -p $(BUILD_DIR)/entity_sets/factory
	@mkdir -p $(BUILD_DIR)/goals
	@mkdir -p $(BUILD_DIR)/jsoncpp
	@mkdir -p $(BUILD_DIR)/models
	@mkdir -p $(BUILD_DIR)/readers
	@mkdir -p $(BUILD_DIR)/writers
	@mkdir -p $(BUILD_DIR)/simulation
	
.PHONY: make_directories

run: compile # compile if needed & run
	./$(NAME)

clean:
	$(RM) *.o *.exe $(NAME) $(NAME).cpp
	$(RM) -rf $(BUILD_DIR)

cc: clean compile # clean compile

ccr: clean run # clean & compile & run

co: #clear output folder
	$(RM) output_data/*
