CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

BUILD_DIR = build

SRCS = $(wildcard *.cpp)
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
	@mkdir  -p $(BUILD_DIR)

.PHONY: directories

clean:
	$(RM) *.o *.exe *.gch core main test/TestCase $(BUILD_DIR)/*.o
	rmdir $(BUILD_DIR)
