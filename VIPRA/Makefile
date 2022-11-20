CPP= g++
CPP_FLAGS= -std=c++17 -w -fPIE -I/usr/include/antlr4-runtime

EXE_NAME: VIPRA_SIM

ifeq ($(DEBUG_OUTPUT), 1)
	CPP_FLAGS := $(CPP_FLAGS) -DDEBUG_OUTPUT=1 -g -O0
else
	CPP_FLAGS := $(CPP_FLAGS) -O3
endif

LDLIBS = -lantlr4-runtime

BASE_DIR = ./Base
BUILD_DIR = ./build

OBJS := $(wildcard $(BUILD_DIR)/*.o) $(wildcard $(BUILD_DIR)/*/*.o)
OBJS := $(filter-out $(wildcard $(BUILD_DIR)/*/main.o), $(OBJS))

PCH_SOURCE= $(BASE_DIR)/_pch/pch.hpp
PCH_HEADERS= 
PCH_OUT= $(PCH_SOURCE).gch
PCH_INCLUDE= -include $(PCH_SOURCE)

generate_main:
	$(CPP) $(CPP_FLAGS) $(PCH_INCLUDE) $(BASE_DIR)/code_generation/code_generator.cpp $(BASE_DIR)/jsoncpp/jsoncpp.cpp $(BASE_DIR)/configuration/configuration_reader.cpp -o $@

module: makeDirs
	$(CPP) $(CPP_FLAGS) $(PCH_INCLUDE) -c $(MODULEPATH).cpp -o $(BUILD_DIR)/$(MODULEID).o

simulation: makeDirs
	$(CPP) $(CPP_FLAGS) $(PCH_INCLUDE) $(BUILD_DIR)/$(BID)/main.o $(OBJS) $(LDLIBS) -o $(BUILD_DIR)/$(BID)/$(EXE_NAME)

compileMain: makeDirs
	./generate_main $(BUILD_DIR)/$(BID)/main.cpp $(MODULEFILE)
	$(CPP) $(CPP_FLAGS) -c $(BASE_DIR)/jsoncpp/jsoncpp.cpp -o $(BUILD_DIR)/jsoncpp.o
	$(CPP) $(CPP_FLAGS) $(PCH_INCLUDE) -c $(BUILD_DIR)/$(BID)/main.cpp -o $(BUILD_DIR)/$(BID)/main.o

precompileHeaders: $(PCH_SOURCE) $(PCH_HEADERS)
	$(CPP) $(CPP_FLAGS) $(BASE_DIR)/_pch/pch.hpp

clean:
	rm -rf generate_main main.cpp VIPRA $(BUILD_DIR) $(BUILD_DIR)/_pch/pch.hpp.gch

cleanObjs:
	rm -rf $(BUILD_DIR)/*.o

makeDirs:
	mkdir -p $(BUILD_DIR)

PHONY: makeDirs