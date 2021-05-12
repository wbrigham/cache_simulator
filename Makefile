# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS flags
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj

# make initialize
initialize:
	rm -rf $(OBJ)/* $(EXE)/*
	mkdir $(OBJ) $(EXE)

# Command: make main

$(OBJ)/LRUCache.o: $(SRC)/LRUCache.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/LRUCache.cpp -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/main.cpp -o $@

mainObjs := $(OBJ)/LRUCache.o $(OBJ)/main.o

main: $(mainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/main $(mainObjs)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
