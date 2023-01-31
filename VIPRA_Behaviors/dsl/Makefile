CPP= g++
CPP_FLAGS= -std=c++17 -w -O3 -fPIE
LDLIBS = -lantlr4-runtime

VIPRA_DIR = ./../../VIPRA
INCLUDES = -I/usr/include/antlr4-runtime -I$(VIPRA_DIR)/deps -I$(VIPRA_DIR)/Base -I$(VIPRA_DIR)/Extendable

BUILD_DIR = $(VIPRA_DIR)/build
SRCS = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

compile: $(OBJECTS)

$(BUILD_DIR)/%.o: %.cpp setup
	$(CPP) $(CPP_FLAGS) $(LDLIBS) $(INCLUDES) -c $< -o $@

.PHONY: setup

setup:
	mkdir -p $(BUILD_DIR)/actions
	mkdir -p $(BUILD_DIR)/conditions
	mkdir -p $(BUILD_DIR)/generated
	mkdir -p $(BUILD_DIR)/selectors
	mkdir -p $(BUILD_DIR)/transitions