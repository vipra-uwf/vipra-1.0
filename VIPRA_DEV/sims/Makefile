CPP= g++
CPP_FLAGS= -std=c++17 -Wall -O3 -fopenmp -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BASE_DIR = ../Base
BUILD_DIR = ../build

OBJS := $(wildcard $(BUILD_DIR)/*.o) $(wildcard $(BUILD_DIR)/*/*.o)
OBJS := $(filter-out $(BUILD_DIR)/main.o, $(OBJS))

generate_main:
	$(CPP) $(CPP_FLAGS) $(BASE_DIR)/code_generation/code_generator.cpp $(BASE_DIR)/jsoncpp/jsoncpp.cpp $(BASE_DIR)/configuration/configuration_reader.cpp -o $@

module:
	$(CPP) $(CPP_FLAGS) -c $(MODULEPATH).cpp -o $(BUILD_DIR)/$(MODULEID).o

simulation:
	$(CPP) $(CPP_FLAGS) $(BUILD_DIR)/main.o $(OBJS) $(LDLIBS) -o VIPRA

# TODO: move the compilation of jsoncpp
compileMain:
	./generate_main main.cpp $(MODULEFILE)
	$(CPP) $(CPP_FLAGS) -c $(BASE_DIR)/jsoncpp/jsoncpp.cpp -o $(BUILD_DIR)/jsoncpp.o
	$(CPP) $(CPP_FLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/main.o:
	$(CPP) $(CPP_FLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

# TODO: add in compilation of base objects like jsoncpp etc

clean:
	rm -f generate_main main.cpp