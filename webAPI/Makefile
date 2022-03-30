CXX = g++
NAME = generated_main

# For Fedora 35, run dnf install antlr4-cpp-runtime-devel
# For Ubuntu 20.04, run apt install libantlr4-runtime-dev libstdc++-10-dev
# The include paths are the same for both platforms
CXXFLAGS = -std=c++11 -g -Wall -O3 -fopenmp -fPIE -I/usr/include/antlr4-runtime
LDLIBS = -lantlr4-runtime

BASE_DIR = ./../VIPRA
UNIQUE_DIR = $(BASE_DIR)/input_data/$(CONFIG_ID)

BUILD_DIR = $(BASE_DIR)/build
GEN_MAIN_DIR = $(UNIQUE_DIR)/build
OBJECTS := $(shell find $(BUILD_DIR) -name '*.o')

$(info $$OBJECTS is [${OBJECTS}])

main: $(GEN_MAIN_DIR)/generated_main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(UNIQUE_DIR)/$(NAME) $^ $(LDLIBS)

$(GEN_MAIN_DIR)/generated_main.o: $(UNIQUE_DIR)/generated_main.cpp main_build_dir
	$(CXX) $(CXXFLAGS) -c $< -o $(GEN_MAIN_DIR)/generated_main.o

main_build_dir:
	@mkdir -p $(GEN_MAIN_DIR)

setup:
	@test -e $(BASE_DIR)/rapidxml || git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git $(BASE_DIR)/rapidxml
	@rm -rf $(BASE_DIR)/rapidxml/.git
	@rm -rf $(BASE_DIR)/rapidxml/test

.PHONY: main_build_dir

clean: 
ifndef CONFIG_ID
	$(error CONFIG_ID is not set)
endif
	$(RM) -r -f $(UNIQUE_DIR)/build $(UNIQUE_DIR)/generated_main $(UNIQUE_DIR)/generated_main.cpp
