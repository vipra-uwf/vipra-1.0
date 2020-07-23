CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
MOREFLAGS = -I/usr/include/python3.8 -lpython3.8
NAME = "RunAnim"

compile: main.cpp ../../VIPRA/readers/xml_reader.cpp ../../VIPRA/simulation/data.cpp ../../VIPRA/entity_sets/obstacle_set.cpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $^ $(MOREFLAGS)

run: compile
	./$(NAME)

clean:
	$(RM) $(NAME)

cc: clean compile

ccr: clean compile run