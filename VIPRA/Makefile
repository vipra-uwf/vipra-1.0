CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

SRCS = $(wildcard *.cpp)
OBJECTS = $(SRCS:%.cpp=%.o)

HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	$(RM) *.o *.exe *.gch core main test/TestCase