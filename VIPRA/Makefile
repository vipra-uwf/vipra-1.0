CC = g++
CFLAGS  = -std=c++11 -g -Wall

OBJECTS = simulation.o xmlreader.o data.o calm_pedestrian_model.o
HEADERS := $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	$(RM) *.o *.gch core main test/TestCase
