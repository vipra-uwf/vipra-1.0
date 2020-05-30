CC = g++
CFLAGS  = -std=c++11 -g -Wall

SRCS = $(wildcard *.cpp)#use any .cpp files

OBJECTS = $(SRCS:%.cpp=%.o)

HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	$(RM) *.o *.gch core main test/TestCase
