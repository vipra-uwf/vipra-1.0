CXX = g++
NAME = generated_main

# For Fedora 35, run dnf install antlr4-cpp-runtime-devel
# For Ubuntu 20.04, run apt install libantlr4-runtime-dev libstdc++-10-dev
# The include paths are the same for both platforms
CXXFLAGS = -std=c++11 -g -Wall -O3 -fopenmp -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BASE_DIR = ./..
UNIQUE_DIR = $(BASE_DIR)/input_data/$(CONFIG_ID)

BUILD_DIR = $(UNIQUE_DIR)/build
SRCS = $($(BASE_DIR)*.cpp) $(wildcard $(BASE_DIR)*/*.cpp) $(wildcard $(BASE_DIR)*/*/*.cpp)
SRCS := $(filter-out code_generation/code_generator.cpp code_generation/code_generator_webAPI.cpp, $(SRCS)) #this gets compiled separately
OBJECTS = $(SRCS:./../%.cpp=$(BUILD_DIR)/%.o)


all: compile

grammar: Behaviors.g4
	antlr4 -Dlanguage=Cpp -o dsl/generated -Dlanguage=Cpp -no-listener -visitor Behaviors.g4 

compile: setup generate_main make_directories main

generate_main:
	$(CXX) $(CXXFLAGS) $(BASE_DIR)/code_generation/code_generator_webAPI.cpp $(BASE_DIR)/jsoncpp/jsoncpp.cpp $(BASE_DIR)/configuration/configuration_reader.cpp -o $(UNIQUE_DIR)/$@
	$(UNIQUE_DIR)/$@ $(CONFIG_ID)
#rm $(UNIQUE_DIR)/$@
	$(eval SRCS := $(NAME).cpp)
#echo $(OBJECTS)
	
main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$(NAME) $^ $(LDLIBS)
	
$(BUILD_DIR)/%.o: $(BASE_DIR)/%.cpp
	echo "HERE----------------"
	echo $@
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
	@mkdir -p $(BUILD_DIR)/dsl/actions
	@mkdir -p $(BUILD_DIR)/dsl/conditions
	@mkdir -p $(BUILD_DIR)/dsl/generated
	@mkdir -p $(BUILD_DIR)/dsl/selectors
	@mkdir -p $(BUILD_DIR)/dsl/transitions
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
#$(RM) *.o *.exe $(NAME) $(NAME).cpp
#$(RM) -rf $(BUILD_DIR)

cc: clean compile # clean compile

ccr: clean run # clean & compile & run

co: #clear output folder
	$(RM) output_data/*

