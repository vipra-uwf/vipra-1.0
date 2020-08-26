CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
NAME = "main"

BUILD_DIR = build
SRCS = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o) 


compile: setup directories main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^
	
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

setup:
	@test -e rapidxml || git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git rapidxml
	@rm -rf ./rapidxml/.git

directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/entity_sets
	@mkdir -p $(BUILD_DIR)/entity_sets/factory
	@mkdir -p $(BUILD_DIR)/goals
	@mkdir -p $(BUILD_DIR)/models
	@mkdir -p $(BUILD_DIR)/readers
	@mkdir -p $(BUILD_DIR)/writers
	@mkdir -p $(BUILD_DIR)/simulation
	
.PHONY: directories

run: compile # compile if needed & run
	./$(NAME)

clean:
	$(RM) *.o *.exe $(NAME)
	$(RM) -rf $(BUILD_DIR)

cc: clean compile # clean compile

ccr: clean run # clean & compile & run

co: #clear output folder
	$(RM) output_data/*





