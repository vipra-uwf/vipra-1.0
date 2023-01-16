CPP= g++
CPP_FLAGS= -std=c++20 -w -fPIE 

EXE_NAME= VIPRA_SIM

ifeq ($(DEBUG_OUTPUT), 1)
	CPP_FLAGS := $(CPP_FLAGS) -DDEBUG_OUTPUT=1 -g -O0
else
	CPP_FLAGS := $(CPP_FLAGS) -O3
endif

LDLIBS = -lantlr4-runtime


BASE_DIR = ./Base
BUILD_DIR = ./build
DEPS_DIR = ./deps

INCLUDES = -I/usr/include/antlr4-runtime -Ideps -IBase -IExtendable

OBJS := $(wildcard $(BUILD_DIR)/*.o) $(wildcard $(BUILD_DIR)/*/*.o)
OBJS := $(filter-out $(wildcard $(BUILD_DIR)/*/main.o), $(OBJS))

generate_main:
	$(CPP) $(CPP_FLAGS) $(INCLUDES) $(BASE_DIR)/code_generation/code_generator.cpp $(DEPS_DIR)/jsoncpp/jsoncpp.cpp $(BASE_DIR)/configuration/configuration_reader.cpp -o $@

module: makeDirs
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $(MODULEPATH).cpp -o $(BUILD_DIR)/$(MODULEID).o

simulation: makeDirs
	$(CPP) $(CPP_FLAGS) $(INCLUDES) $(BUILD_DIR)/$(BID)/main.o $(OBJS) $(LDLIBS) -o $(BUILD_DIR)/$(BID)/$(EXE_NAME)

compileMain: makeDirs
	./generate_main $(BUILD_DIR)/$(BID)/main.cpp $(MODULEFILE)
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $(DEPS_DIR)/jsoncpp/jsoncpp.cpp -o $(BUILD_DIR)/jsoncpp.o
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -c $(BUILD_DIR)/$(BID)/main.cpp -o $(BUILD_DIR)/$(BID)/main.o

makeDirs:
	mkdir -p $(BUILD_DIR)

GenMain:
	cmake -B genbuild . -DDEBUG_MODE=OFF
	cmake --build genbuild 

GenSim:
	cmake -B simbuild . -DGEN_MAIN=OFF -DDEBUG_MODE=OFF
	cmake --build simbuild

DebugGenMain:
	cmake -B genbuild . -DDEBUG_MODE=ON
	cmake --build genbuild 

DebugGenSim:
	cmake -B simbuild . -DGEN_MAIN=OFF -DDEBUG_MODE=ON
	cmake --build simbuild

BuildAll:
	node ../VIPRA_Launcher/server/dist/index.js -noserver -nobuild
	make GenMain
	./generate_main main.cpp ../VIPRA_Launcher/server/dist/configuration/modules.json -noCompReq
	make GenSim

DebugBuildAll:
	node ../VIPRA_Launcher/server/dist/index.js -noserver -nobuild
	make DebugGenMain
	./generate_main main.cpp ../VIPRA_Launcher/server/dist/configuration/modules.json -noCompReq
	make DebugGenSim

PHONY: makeDirs GenMain GenSim BuildAll DebugBuildAll