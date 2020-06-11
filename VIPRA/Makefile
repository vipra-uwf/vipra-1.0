CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

BUILD_DIR = build

SRCS = $(wildcard *.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	$(RM) *.o *.exe *.gch core main test/TestCase $(BUILD_DIR)/*.o
