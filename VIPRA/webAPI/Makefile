CXX = g++
NAME = generated_main

# For Fedora 35, run dnf install antlr4-cpp-runtime-devel
# For Ubuntu 20.04, run apt install libantlr4-runtime-dev libstdc++-10-dev
# The include paths are the same for both platforms
CXXFLAGS = -std=c++11 -g -Wall -O3 -fopenmp -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BASE_DIR = ./..
UNIQUE_DIR = $(BASE_DIR)/input_data/$(CONFIG_ID)

BUILD_DIR = $(BASE_DIR)/build
GEN_MAIN_DIR = $(UNIQUE_DIR)/build
SRCS = $($(BASE_DIR)/*.cpp) $(wildcard $(BASE_DIR)/*/*.cpp) $(wildcard $(BASE_DIR)/*/*/*.cpp)
SRCS := $(filter-out $(UNIQUE_DIR)/generated_main.cpp $(BASE_DIR)/code_generation/code_generator.cpp, $(SRCS)) #this gets compiled separately
OBJECTS = $(SRCS:./../%.cpp=$(BUILD_DIR)/%.o)

main: $(GEN_MAIN_DIR)/generated_main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(UNIQUE_DIR)/$(NAME) $^ $(LDLIBS)

$(GEN_MAIN_DIR)/generated_main.o: $(UNIQUE_DIR)/generated_main.cpp main_build_dir
	$(CXX) $(CXXFLAGS) -c $< -o $(GEN_MAIN_DIR)/generated_main.o

main_build_dir:
	@mkdir -p $(GEN_MAIN_DIR)

grammar: Behaviors.g4
	antlr4 -Dlanguage=Cpp -o dsl/generated -Dlanguage=Cpp -no-listener -visitor Behaviors.g4

setup:
	@test -e $(BASE_DIR)/rapidxml || git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git $(BASE_DIR)/rapidxml
	@rm -rf $(BASE_DIR)/rapidxml/.git
	@rm -rf $(BASE_DIR)/rapidxml/test

.PHONY: main_build_dir

run: compile # compile if needed & run
	./$(NAME)

clean$(CONFIG_ID):
	$(RM) -r -f $(UNIQUE_DIR)/build $(UNIQUE_DIR)/generated_main $(UNIQUE_DIR)/generated_main.cpp

