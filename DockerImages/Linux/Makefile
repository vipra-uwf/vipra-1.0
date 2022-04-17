CXX = g++
NAME = "VIPRA_Sim"

# For Fedora 35, run dnf install antlr4-cpp-runtime-devel
# For Ubuntu 20.04, run apt install libantlr4-runtime-dev libstdc++-10-dev
# The include paths are the same for both platforms
CXXFLAGS = -std=c++11 -g -Wall -O3 -fopenmp -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BUILD_DIR = Build

SRCS = generated_main.cpp $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJECTS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(info $$SRCS is [${SRCS}])
$(info $$OBJECTS is [${OBJECTS}])

simulation: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^ $(LDLIBS)

$(BUILD_DIR)/%.o: %.cpp
	echo $@
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
.PHONY: make_directories