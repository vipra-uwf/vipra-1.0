CPP= g++
CPP_FLAGS= -std=c++17 -w -O3 -fPIE -I/usr/include/antlr4-runtime

ifeq ($(DEBUG_OUTPUT), 1)
	CPP_FLAGS := $(CPP_FLAGS) -DDEBUG_OUTPUT=1
endif

LDLIBS = -lantlr4-runtime

BASE_DIR = ./../Base
BUILD_DIR = ./../build

OBJS := $(wildcard $(BUILD_DIR)/*.o) $(wildcard $(BUILD_DIR)/*/*.o)
OBJS := $(filter-out $(BUILD_DIR)/main.o, $(OBJS))

generate_main:
	$(CPP) $(CPP_FLAGS) $(BASE_DIR)/code_generation/code_generator.cpp $(BASE_DIR)/jsoncpp/jsoncpp.cpp $(BASE_DIR)/configuration/configuration_reader.cpp -o $@

module: makeDirs
	$(CPP) $(CPP_FLAGS) -c $(MODULEPATH).cpp -o $(BUILD_DIR)/$(MODULEID).o

simulation: makeDirs
	$(CPP) $(CPP_FLAGS) $(BUILD_DIR)/main.o $(OBJS) $(LDLIBS) -o VIPRA

compileMain: makeDirs
	./generate_main main.cpp $(MODULEFILE)
	$(CPP) $(CPP_FLAGS) -c $(BASE_DIR)/jsoncpp/jsoncpp.cpp -o $(BUILD_DIR)/jsoncpp.o
	$(CPP) $(CPP_FLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/main.o: makeDirs
	$(CPP) $(CPP_FLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

testrun:
	./VIPRA ./example/sim.config ./example/module_params.json ./../pedestrian_maps/a320_144_pedestrians.json ./../obstacle_maps/a320_144_obstacles.json ./output.json

clean:
	rm -f generate_main main.cpp VIPRA

cleanObjs:
	rm -rf $(BUILD_DIR)/*.o

makeDirs:
	mkdir -p $(BUILD_DIR)

PHONY: makeDirs