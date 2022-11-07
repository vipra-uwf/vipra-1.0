CPP= g++
CPP_FLAGS= -std=c++17 -w -O3 -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BUILD_DIR = ./../../build
SRCS = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

grammar: Behaviors.g4
	antlr4 -Dlanguage=Cpp -o generated -Dlanguage=Cpp -no-listener -visitor Behaviors.g4

compile: $(OBJECTS)
	echo "Complete"

$(BUILD_DIR)/%.o: %.cpp setup
	$(CPP) $(CPP_FLAGS) $(LDLIBS) -c $< -o $@

.PHONY: setup

setup:
	mkdir -p $(BUILD_DIR)/actions
	mkdir -p $(BUILD_DIR)/conditions
	mkdir -p $(BUILD_DIR)/generated
	mkdir -p $(BUILD_DIR)/selectors
	mkdir -p $(BUILD_DIR)/transitions