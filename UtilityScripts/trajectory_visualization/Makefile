CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
MOREFLAGS = -I/usr/include/python3.8 -lpython3.8
NAME = "RunAnim"

compile: main.cpp ../../VIPRA/readers/input_xml_reader.cpp ../../VIPRA/simulation/data.cpp ../../VIPRA/entity_sets/obstacle_set.cpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $^ $(MOREFLAGS)

run: compile # compile if needed & run
	./$(NAME)

clean:
	$(RM) $(NAME)

cc: clean compile # clean & compile

ccr: clean run # clean & compile & run