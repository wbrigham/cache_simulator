# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS flags
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj

# make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*

# Command: make cache
cacheObjs := $(OBJ)/cache.o

cache: $(cacheObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/cache $(cacheObjs)

$(OBJ)/cache.o: $(SRC)/cache.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/cache.cpp -o $@

# Command: make main

mainObjs := $(OBJ)/main.o

main: $(mainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/main $(mainObjs)

$(OBJ)/main.o: $(SRC)/main.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/main.cpp -o $@

