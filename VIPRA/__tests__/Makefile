CPP= g++
CPP_FLAGS= -std=c++17 -w -fPIE

BASE_DIR = ./../Base
BUILD_DIR = ./build

SRCS_FILE = ./sources
SRC_DIRS := $(shell cat $(SRCS_FILE))
SRCS := $(foreach dir,$(SRC_DIRS), $(wildcard $(dir)/*.cpp) $(wildcard $(dir)/*/*.cpp))

Test: clean
	$(CPP) $(CPP_FLAGS) $(SRCS) Testing.cpp -o $@

clean:
	rm -f Test

PHONY: clean