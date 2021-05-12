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

# Command: make main

$(OBJ)/Node.o: $(SRC)/Node.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Node.cpp -o $@

$(OBJ)/DDList.o: $(SRC)/DDList.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/DDList.cpp -o $@

$(OBJ)/LFUCache.o: $(SRC)/LFUCache.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/LFUCache.cpp -o $@

$(OBJ)/mainLFU.o: $(SRC)/mainLFU.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/mainLFU.cpp -o $@

mainObjs := $(OBJ)/Node.o $(OBJ)/DDList.o $(OBJ)/LFUCache.o $(OBJ)/mainLFU.o

main: $(mainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/main $(mainObjs)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
