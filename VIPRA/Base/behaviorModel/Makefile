CPP= g++
CPP_FLAGS= -std=c++17 -w -O3 -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

DSL_DIR = ./dsl
BUILD_DIR = ./../../build
SRCS = $(wildcard $(DSL_DIR)/*.cpp) $(wildcard $(DSL_DIR)/*/*.cpp) $(wildcard $(DSL_DIR)/*/*/*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

grammar: $(DSL_DIR)/Behaviors.g4
	antlr4 -Dlanguage=Cpp -o generated -Dlanguage=Cpp -no-listener -visitor $(DSL_DIR)/Behaviors.g4

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