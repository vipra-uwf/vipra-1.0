CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

BUILD_DIR = build

SRCS = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o) 

all: setup directories main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

setup:
	@test -e rapidxml || git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git rapidxml
	@rm -rf ./rapidxml/.git

directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/entity_sets
	@mkdir -p $(BUILD_DIR)/goals
	@mkdir -p $(BUILD_DIR)/models
	@mkdir -p $(BUILD_DIR)/readers
	@mkdir -p $(BUILD_DIR)/writers
	@mkdir -p $(BUILD_DIR)/simulation
	
.PHONY: directories

clean:
	$(RM) *.o *.exe $(BUILD_DIR)/*.o
	$(RM) -rf $(BUILD_DIR)
